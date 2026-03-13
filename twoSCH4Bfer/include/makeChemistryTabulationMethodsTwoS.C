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

#include "makeChemistryTabulationMethods.H"

#include "thermoPhysicsTypesTwoS.H"

#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // Chemistry solvers based on sensibleEnthalpy
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferGasHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferPengRobinsonGasHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferincompressibleGasHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BfergasEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferPengRobinsonGasEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferincompressibleGasEThermoPhysics);



    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstGasHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstIncompressibleGasHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstFluidHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstrPolFluidHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstHThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstGasEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstIncompressibleGasEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstFluidEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstAdiabaticFluidEThermoPhysics);
    makeChemistryTabulationMethods(rhoReactionThermo, twoSCH4BferConstEThermoPhysics);


    
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
