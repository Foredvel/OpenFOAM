/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2012-2017 OpenFOAM Foundation
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

#include "reactionTypes.H"
#include "makeReaction.H"
#include "reactionTypesTwoS.H"

#include "ArrheniusReactionRateExtend.H"
#include "infiniteReactionRate.H"
#include "LandauTellerReactionRate.H"
#include "thirdBodyArrheniusReactionRate.H"

#include "ChemicallyActivatedReactionRate.H"
#include "JanevReactionRate.H"
#include "powerSeriesReactionRate.H"

#include "FallOffReactionRate.H"
#include "LindemannFallOffFunction.H"
#include "SRIFallOffFunction.H"
#include "TroeFallOffFunction.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeReactions(Thermo, Reaction)                                        \
                                                                               \
    									       \
    makeIRNReactions(Thermo, ArrheniusReactionRateExtend)                      \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRateExtend,                                            \
       LindemannFallOffFunction                                                \
    )                                                                          \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRateExtend,                                            \
       TroeFallOffFunction                                                     \
    )                                                                          \
                                                                               \
    makePressureDependentReactions                                             \
    (                                                                          \
       Thermo,                                                                 \
       ArrheniusReactionRateExtend,                                            \
       SRIFallOffFunction                                                      \
    )


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // sensible enthalpy based reactions
    makeReactions(constGasHThermoPhysics, constGasHReaction)
    makeReactions(gasHThermoPhysics, gasHReaction)
    makeReactions(PengRobinsonGasHThermoPhysics, PengRobinsonGasHReaction)
    makeReactions
    (
        constIncompressibleGasHThermoPhysics,
        constIncompressibleGasHReaction
    )
    makeReactions(incompressibleGasHThermoPhysics, incompressibleGasHReaction)
    makeReactions(icoPoly8HThermoPhysics, icoPoly8HReaction)
    makeReactions(constFluidHThermoPhysics, constFluidHReaction)
    makeReactions
    (
        constAdiabaticFluidHThermoPhysics,
        constAdiabaticFluidHReaction
    )
    makeReactions(constHThermoPhysics, constHReaction)


    makeReactions(constGasEThermoPhysics, constGasEReaction)
    makeReactions(gasEThermoPhysics, gasEReaction)
    makeReactions(PengRobinsonGasEThermoPhysics, PengRobinsonGasEReaction)
    makeReactions
    (
        constIncompressibleGasEThermoPhysics,
        constIncompressibleGasEReaction
    )
    makeReactions(incompressibleGasEThermoPhysics, incompressibleGasEReaction)
    makeReactions(icoPoly8EThermoPhysics, icoPoly8EReaction)
    makeReactions(constFluidEThermoPhysics, constFluidEReaction)
    
    makeReactions
    (
        constAdiabaticFluidEThermoPhysics,
        constAdiabaticFluidEReaction
    )
    
    makeReactions(constEThermoPhysics, constEReaction)

    makeReactions(twoSCH4BferConstGasHThermoPhysics, twoSCH4BferConstGasHReaction);
    makeReactions(twoSCH4BferConstIncompressibleGasHThermoPhysics, twoSCH4BferConstIncompressibleGasHReaction);
    makeReactions(twoSCH4BferConstFluidHThermoPhysics, twoSCH4BferConstFluidHReaction);
    makeReactions(twoSCH4BferConstrPolFluidHThermoPhysics, twoSCH4BferConstrPolFluidHReaction);
    makeReactions(twoSCH4BferConstAdiabaticFluidHThermoPhysics, twoSCH4BferConstAdiabaticFluidHReaction);
    makeReactions(twoSCH4BferConstHThermoPhysics, twoSCH4BferConstHReaction);
    makeReactions(twoSCH4BferConstGasEThermoPhysics, twoSCH4BferConstGasEReaction);
    makeReactions(twoSCH4BferConstIncompressibleGasEThermoPhysics, twoSCH4BferConstIncompressibleGasEReaction);
    makeReactions(twoSCH4BferConstFluidEThermoPhysics, twoSCH4BferConstFluidEReaction);
    makeReactions(twoSCH4BferConstAdiabaticFluidEThermoPhysics, twoSCH4BferConstAdiabaticFluidEReaction);
    makeReactions(twoSCH4BferConstEThermoPhysics, twoSCH4BferConstEReaction);
    
    makeReactions(twoSCH4BferGasHThermoPhysics, twoSCH4BferGasHReaction);
    makeReactions(twoSCH4BferPengRobinsonGasHThermoPhysics, twoSCH4BferPengRobinsonGasHReaction);
    makeReactions(twoSCH4BferincompressibleGasHThermoPhysics, twoSCH4BferincompressibleGasHReaction);
    makeReactions(twoSCH4BfergasEThermoPhysics, twoSCH4BfergasEReaction);
    makeReactions(twoSCH4BferPengRobinsonGasEThermoPhysics, twoSCH4BferPengRobinsonGasEReaction);
    makeReactions(twoSCH4BferincompressibleGasEThermoPhysics, twoSCH4BferincompressibleGasEReaction);

}

// ************************************************************************* //
