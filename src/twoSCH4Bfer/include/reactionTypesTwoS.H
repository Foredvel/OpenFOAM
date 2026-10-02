/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2013 OpenFOAM Foundation
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

Typedefs
    Foam::reactionTypes

Description
    Type definitions for reactions

\*---------------------------------------------------------------------------*/

#ifndef reactionTypesTwoS_H
#define reactionTypesTwoS_H

#include "thermoPhysicsTypesTwoS.H"
#include "Reaction.H"

#include "icoPolynomial.H"
#include "hPolynomialThermo.H"
#include "polynomialTransport.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    typedef Reaction<twoSCH4BferGasHThermoPhysics> twoSCH4BferGasHReaction;
    typedef Reaction<twoSCH4BferPengRobinsonGasHThermoPhysics> twoSCH4BferPengRobinsonGasHReaction;
    typedef Reaction<twoSCH4BferincompressibleGasHThermoPhysics> twoSCH4BferincompressibleGasHReaction;
    typedef Reaction<twoSCH4BfergasEThermoPhysics> twoSCH4BfergasEReaction;
    typedef Reaction<twoSCH4BferPengRobinsonGasEThermoPhysics> twoSCH4BferPengRobinsonGasEReaction;
    typedef Reaction<twoSCH4BferincompressibleGasEThermoPhysics> twoSCH4BferincompressibleGasEReaction;

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    typedef Reaction<twoSCH4BferConstGasHThermoPhysics> twoSCH4BferConstGasHReaction;
    typedef Reaction<twoSCH4BferConstIncompressibleGasHThermoPhysics> twoSCH4BferConstIncompressibleGasHReaction;
    typedef Reaction<twoSCH4BferConstFluidHThermoPhysics> twoSCH4BferConstFluidHReaction;
    typedef Reaction<twoSCH4BferConstrPolFluidHThermoPhysics> twoSCH4BferConstrPolFluidHReaction;
    typedef Reaction<twoSCH4BferConstAdiabaticFluidHThermoPhysics> twoSCH4BferConstAdiabaticFluidHReaction;
    typedef Reaction<twoSCH4BferConstHThermoPhysics> twoSCH4BferConstHReaction;
    typedef Reaction<twoSCH4BferConstGasEThermoPhysics> twoSCH4BferConstGasEReaction;
    typedef Reaction<twoSCH4BferConstIncompressibleGasEThermoPhysics> twoSCH4BferConstIncompressibleGasEReaction;
    typedef Reaction<twoSCH4BferConstFluidEThermoPhysics> twoSCH4BferConstFluidEReaction;
    typedef Reaction<twoSCH4BferConstAdiabaticFluidEThermoPhysics> twoSCH4BferConstAdiabaticFluidEReaction;
    typedef Reaction<twoSCH4BferConstEThermoPhysics> twoSCH4BferConstEReaction;
    typedef Reaction<twoSCH4BfericoPoly8HThermoPhysics> twoSCH4BfericoPoly8HReaction;
    typedef Reaction<twoSCH4BfericoPoly8EThermoPhysics> twoSCH4BfericoPoly8EReaction;




    /*
    typedef Reaction<twoSCH4BferJanafPengRobinsonGasHThermoPhysics> twoSCH4BferJanafPengRobinsonGasHReaction;
    typedef Reaction<twoSCH4BferJanafincompressibleGasHThermoPhysics> twoSCH4BferJanafincompressibleGasHReaction;
    typedef Reaction<twoSCH4BferJanafgasEThermoPhysics> twoSCH4BferJanafgasEReaction;
    typedef Reaction<twoSCH4BferJanafPengRobinsonGasEThermoPhysics> twoSCH4BferJanafPengRobinsonGasEReaction;
    typedef Reaction<twoSCH4BferJanafincompressibleGasEThermoPhysics> twoSCH4BferJanafincompressibleGasEReaction;
    */
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
