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

Class
    Foam::ArrheniusReactionRateExtend

Description
    Arrhenius reaction rate given by:

        k = A * T^beta * exp(-Ta/T)*f(phi)

SourceFiles
    ArrheniusReactionRateI.H

\*---------------------------------------------------------------------------*/

#ifndef ArrheniusReactionRateExtend_H
#define ArrheniusReactionRateExtend_H

#include "scalarField.H"
#include "typeInfo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

class ArrheniusReactionRateExtend;

Ostream& operator<<(Ostream&, const ArrheniusReactionRateExtend&);


/*---------------------------------------------------------------------------*\
                    Class ArrheniusReactionRate Declaration
\*---------------------------------------------------------------------------*/

class ArrheniusReactionRateExtend
{
    // Private data

        scalar A_;
        scalar beta_;
        scalar Ta_;
        scalar phiEx_;
        word name_;


public:

    // Constructors

        //- Construct from components
        inline ArrheniusReactionRateExtend
        (
            const scalar A,
            const scalar beta,
            const scalar Ta,
            const scalar phiEx,
            const word& name = word::null
        );

        //- Construct from dictionary
        inline ArrheniusReactionRateExtend
        (
            const speciesTable& species,
            const dictionary& dict
        );


    // Member Functions

        //- Return the type name
        static word type()
        {
            return "ArrheniusExtend";
        }

        inline scalar operator()
        (
            const scalar p,
            const scalar T,
            const scalarField& c
        ) const;

        //- Write to stream
        inline void write(Ostream& os) const;


    // Ostream Operator

        inline friend Ostream& operator<<
        (
            Ostream&,
            const ArrheniusReactionRateExtend&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "ArrheniusReactionRateExtendI.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
