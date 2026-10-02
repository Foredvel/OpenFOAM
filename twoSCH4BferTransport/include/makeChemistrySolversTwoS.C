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

#include "makeChemistrySolverTypes.H"

#include "thermoPhysicsTypesTwoS.H"
#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // Chemistry solvers based on sensibleEnthalpy
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferGasHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferPengRobinsonGasHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferincompressibleGasHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BfergasEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferPengRobinsonGasEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferincompressibleGasEThermoPhysics);

    
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstGasHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstIncompressibleGasHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstFluidHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstrPolFluidHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstHThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstGasEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstIncompressibleGasEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstFluidEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BferConstEThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BfericoPoly8HThermoPhysics);
    makeChemistrySolverTypes(rhoReactionThermo, twoSCH4BfericoPoly8EThermoPhysics);

}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
