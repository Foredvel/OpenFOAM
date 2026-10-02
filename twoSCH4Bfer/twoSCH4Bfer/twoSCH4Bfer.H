/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2020 OpenCFD Ltd.
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

Class
    Foam::constTransport

Group
    grpSpecieTransport

Description
    Constant properties Transport package.
    Templated into a given thermodynamics package (needed for thermal
    conductivity).


\*---------------------------------------------------------------------------*/

#ifndef twoSCH4Bfer_H
#define twoSCH4Bfer_H

#include "scalar.H"
#include "dictionary.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations

template<class Thermo> class twoSCH4Bfer;

template<class Thermo>
inline twoSCH4Bfer<Thermo> operator+
(
    const twoSCH4Bfer<Thermo>&,
    const twoSCH4Bfer<Thermo>&
);

template<class Thermo>
inline twoSCH4Bfer<Thermo> operator*
(
    const scalar,
    const twoSCH4Bfer<Thermo>&
);

template<class Thermo>
Ostream& operator<<
(
    Ostream&,
    const twoSCH4Bfer<Thermo>&
);


/*---------------------------------------------------------------------------*\
                           Class constTransport Declaration
\*---------------------------------------------------------------------------*/

template<class Thermo>
class twoSCH4Bfer
:
    public Thermo
{
    // Private Data

        //- Constant dynamic viscosity [Pa.s]
        scalar mu_;
        scalar T0_;

        //- Is the Prandtl Number constant?
        bool constPr_;

        scalar alpha_;

        //- Reciprocal Prandtl Number [-]
        scalar rPr_;

        //- Constant thermal conductivity [W/m/K]
        scalar kappa_;


    // Private Member Functions




public:

    // Private Member Functions

        //- Construct from components
        inline twoSCH4Bfer
        (
            const Thermo& t,
            const scalar mu,
            const scalar T0,
            const bool constPr,
            const scalar alpha,
            const scalar rPr,
            const scalar kappa
        );

    // Generated Methods: copy construct, copy assignment


    // Constructors
        explicit twoSCH4Bfer(const dictionary& dict);

        //- Construct as named copy
        inline twoSCH4Bfer(const word&, const twoSCH4Bfer&);

        //- Construct and return a clone
        inline autoPtr<twoSCH4Bfer> clone() const;

        // Selector from dictionary
        inline static autoPtr<twoSCH4Bfer> New(const dictionary& dict);


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "twoSCH4Bfer<" + Thermo::typeName() + '>';
        }

        //- Dynamic viscosity [kg/ms]
        inline scalar mu(const scalar p, const scalar T) const;

        //- Thermal conductivity [W/mK]
        inline scalar kappa(const scalar p, const scalar T) const;
        
        inline scalar Pr(const scalar p, const scalar T) const;
        inline scalar T0(const scalar p, const scalar T) const;

        //- Thermal diffusivity of enthalpy [kg/ms]
        inline scalar alphah(const scalar p, const scalar T) const;

        // Species diffusivity
        //inline scalar D(const scalar p, const scalar T) const;

        //- Write to Ostream
        void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const twoSCH4Bfer&);

        inline void operator*=(const scalar);


    // Friend Operators

        friend twoSCH4Bfer operator+ <Thermo>
        (
            const twoSCH4Bfer&,
            const twoSCH4Bfer&
        );

        friend twoSCH4Bfer operator* <Thermo>
        (
            const scalar,
            const twoSCH4Bfer&
        );


    // IOstream Operators

        friend Ostream& operator<< <Thermo>
        (
            Ostream&,
            const twoSCH4Bfer&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "twoSCH4BferI.H"

#ifdef NoRepository
    #include "twoSCH4Bfer.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif


// ************************************************************************* //
