/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2016-2017 OpenFOAM Foundation
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

#include "makeChemistryReductionMethods.H"

#include "thermoPhysicsTypesTwoS.H"

#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // Chemistry solvers based on sensibleEnthalpy
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferGasHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferPengRobinsonGasHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferincompressibleGasHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BfergasEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferPengRobinsonGasEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferincompressibleGasEThermoPhysics);


    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstGasHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstIncompressibleGasHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstFluidHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstrPolFluidHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstHThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstGasEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstIncompressibleGasEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstFluidEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidEThermoPhysics);
    makeChemistryReductionMethods(rhoReactionThermo, twoSCH4BferConstEThermoPhysics);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
