/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
    Copyright (C) 2023 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "fixedValueExtendFvPatchField.H"

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF
)
:
    fvPatchField<Type>(p, iF)
{
	Info<< "!!! fixedValueExtendFvPatchField CONSTRUCTOR for "<< iF.name() << " !!!" << endl;
}


template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const Type& value
)
:
    fvPatchField<Type>(p, iF, value)
{
	Info<< "!!! fixedValueExtendFvPatchField CONSTRUCTOR for "<< iF.name() << " !!!" << endl;
}


template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const dictionary& dict,
    IOobjectOption::readOption requireValue
)
:
    fvPatchField<Type>(p, iF, dict, requireValue),
    origValue_(*this)
{
    if constexpr (std::is_same<Type, scalar>::value)
    {
        const scalar k_O_air         = 0.20946;
        const scalar K_fuel_oxidizer = 0.5;
        const scalar Mass_CH4 = 12.011 + 1.0080*4;
        const scalar Mass_O2  = 15.999*2;
        const scalar Mass_N2  = 14.007*2;

        Field<Type> transformed(origValue_.size());
        
        const word& fieldName = this->internalField().name();
        
        if (fieldName == "CH4" || fieldName == "O2" || fieldName == "N2")
    	{
    	    Field<Type> transformed(origValue_.size());
            
            forAll(origValue_, facei)
            {
            
                const scalar v = origValue_[facei];

                const scalar Y_mole_CH4 =  K_fuel_oxidizer*k_O_air*v / (K_fuel_oxidizer*k_O_air*v + 1);

                const scalar Y_mole_O2 = (1 - Y_mole_CH4)*k_O_air;
                const scalar Y_mole_N2 = 1 - Y_mole_CH4 - Y_mole_O2;

                const scalar Mass_mixture = Mass_CH4*Y_mole_CH4 + Mass_O2*Y_mole_O2 + Mass_N2*Y_mole_N2;
        
    		if (fieldName == "CH4")
    		{
    		    transformed[facei] = Mass_CH4/Mass_mixture*Y_mole_CH4;
    		}
    		else if (fieldName == "O2")
    		{
    		    transformed[facei] = Mass_O2/Mass_mixture*Y_mole_O2;
    		}
    		else if (fieldName == "N2")
    		{
    		    transformed[facei] = Mass_N2/Mass_mixture*Y_mole_N2;
    		}
    		
    		Info<<"////// field: "<< fieldName << " and znacheniye: " << transformed[facei] << " //////" << endl;
    		Field<Type>::operator=(transformed);
    		
            }
        
	}
    }
}


template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fixedValueExtendFvPatchField<Type>& ptf,
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fvPatchField<Type>(ptf, p, iF, mapper)
{
    if (notNull(iF) && mapper.hasUnmapped())
    {
        WarningInFunction
            << "On field " << iF.name() << " patch " << p.name()
            << " patchField " << this->type()
            << " : mapper does not map all values." << nl
            << "    To avoid this warning fully specify the mapping in derived"
            << " patch fields." << endl;
    }
    
    Info<< "!!! fixedValueExtendFvPatchField CONSTRUCTOR for "<< iF.name() << " !!!" << endl;
}


template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fixedValueExtendFvPatchField<Type>& ptf,
    const DimensionedField<Type, volMesh>& iF
)
:
    fvPatchField<Type>(ptf, iF)
{
	Info<< "!!! fixedValueExtendFvPatchField CONSTRUCTOR for "<< iF.name() << " !!!" << endl;
}


template<class Type>
Foam::fixedValueExtendFvPatchField<Type>::fixedValueExtendFvPatchField
(
    const fixedValueExtendFvPatchField<Type>& ptf
)
:
    fixedValueExtendFvPatchField<Type>(ptf, ptf.internalField())
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Type>
Foam::tmp<Foam::Field<Type>>
Foam::fixedValueExtendFvPatchField<Type>::valueInternalCoeffs
(
    const tmp<scalarField>&
) const
{
    return tmp<Field<Type>>::New(this->size(), Foam::zero{});
}



template<class Type>
Foam::tmp<Foam::Field<Type>>
Foam::fixedValueExtendFvPatchField<Type>::valueBoundaryCoeffs
(
    const tmp<scalarField>&
) const
{
    Info << "FIELD: "<< this->internalField().name()<< nl;
    return *this;
}


template<class Type>
Foam::tmp<Foam::Field<Type>>
Foam::fixedValueExtendFvPatchField<Type>::gradientInternalCoeffs() const
{
    return -pTraits<Type>::one*this->patch().deltaCoeffs();
}


template<class Type>
Foam::tmp<Foam::Field<Type>>
Foam::fixedValueExtendFvPatchField<Type>::gradientBoundaryCoeffs() const
{
    return this->patch().deltaCoeffs()*(*this);
}


template<class Type>
void Foam::fixedValueExtendFvPatchField<Type>::write(Ostream& os) const
{
    fvPatchField<Type>::write(os);
    fvPatchField<Type>::writeValueEntry(os);
}



// ************************************************************************* //
