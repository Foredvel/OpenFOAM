/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
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

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline Foam::ArrheniusReactionRateExtend::ArrheniusReactionRateExtend
(
    const scalar A,
    const scalar beta,
    const scalar Ta,
    const word& name
)
:
    A_(A),
    beta_(beta),
    Ta_(Ta),
    phiEx_(readPhi()),
    name_(name)
{
}


inline Foam::ArrheniusReactionRateExtend::ArrheniusReactionRateExtend
(
    const speciesTable&,
    const dictionary& dict
)
:
    A_(dict.get<scalar>("A")),
    beta_(dict.get<scalar>("beta")),
    Ta_(dict.get<scalar>("Ta")),
    phiEx_(readPhi())
{
    name_ = dict.dictName();
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline Foam::scalar Foam::ArrheniusReactionRateExtend::readPhi()
{
    // Читается один раз за запуск, дальше берётся из кэша
    static const scalar phi = []()
    {
        const fileName file
        (
            fileName(getEnv("FOAM_CASE"))/"constant"/"phiEq"
        );

        IFstream is(file);

        if (!is.good())
        {
            FatalErrorInFunction
                << "Cannot open " << file << nl
                << exit(FatalError);
        }

        const dictionary d(is);
        return d.get<scalar>("value");
    }();

    return phi;
}

inline Foam::scalar Foam::ArrheniusReactionRateExtend::operator()
(
    const scalar p,
    const scalar T,
    const scalarField&
) const
{
    scalar ak = A_;

    if (mag(beta_) > VSMALL)
    {
        ak *= pow(T, beta_);
    }

    if (mag(Ta_) > VSMALL)
    {
        ak *= exp(-Ta_/T);
    }
    
    if (name_ == "R1")
    {
        const scalar p_0_1 = 1.1,  s_0_1 = 0.09, b_1 = 0.37,   p_1_1 = 1.13, s_1_1 = 0.03, c_1 = 6.7,    p_2_1 = 1.6, s_2_1 = 0.22;

        scalar f1 = 2.0 / (1.0 + tanh((p_0_1 - phiEx_) / s_0_1) + b_1 * (1.0 + tanh((phiEx_ - p_1_1) / s_1_1)) + c_1 * (1.0 + tanh((phiEx_ - p_2_1) / s_2_1)));
        
        ak *= f1;
    }
    else if (name_ == "R2")
    {
     	const scalar p_0_2 = 0.95, s_0_2 = 0.08, b_2 = 2.5e-5, p_1_2 = 1.3,  s_1_2 = 0.04, c_2 = 0.0087, p_2_2 = 1.2, s_2_2 = 0.04, p_3_2 = 1.2, s_3_2 = 0.05;  
        
        scalar f2 = 0.5 * (1.0 + tanh((p_0_2 - phiEx_) / s_0_2)) + 0.5 * b_2 * (1.0 + tanh((phiEx_ - p_1_2) / s_1_2)) + 0.5 * c_2 * (1.0 + tanh((phiEx_ - p_2_2) / s_2_2)) * (1.0 + tanh((p_3_2 - phiEx_) / s_3_2));

        ak *= f2;
    }
        
    return ak;
}


inline void Foam::ArrheniusReactionRateExtend::write(Ostream& os) const
{
    os.writeEntry("A", A_);
    os.writeEntry("beta", beta_);
    os.writeEntry("Ta", Ta_);
    os.writeEntry("name", name_);
    os.writeEntry("phi", phiEx_);
}


inline Foam::Ostream& Foam::operator<<
(
    Ostream& os,
    const ArrheniusReactionRateExtend& arr
)
{
    arr.write(os);
    return os;
}


// ************************************************************************* //
