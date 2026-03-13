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
#ifndef PSITHERMO_H
#define PSITHERMO_H

// ----------------- Basic Chemistry Models ----------------- //
#include "makeChemistryModel.H"
#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"
#include "StandardChemistryModel.H"
#include "TDACChemistryModel.H"
#include "thermoPhysicsTypesTwoS.H"

// ----------------- Chemistry Readers ----------------- //
#include "makeReactionThermo.H"
#include "chemistryReader.H"
#include "foamChemistryReader.H"

// ----------------- Chemistry Reduction Methods ----------------- //
#include "makeChemistryReductionMethods.H"

// ----------------- Chemistry Solvers ----------------- //
#include "makeChemistrySolverTypes.H"

// ----------------- Chemistry Tabulation Methods ----------------- //
#include "makeChemistryTabulationMethods.H"

// ----------------- Reactions ----------------- //
#include "reactionTypesTwoS.H"
#include "makeReaction.H"

#include "ArrheniusReactionRate.H"
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

// ----------------- Thermophysical Models ----------------- //
#include "thermoPhysicsTypesTwoS.H"
#include "Reaction.H"
#include "icoPolynomial.H"
#include "hPolynomialThermo.H"
#include "polynomialTransport.H"

#include "specie.H"
#include "perfectGas.H"
#include "PengRobinsonGas.H"
#include "incompressiblePerfectGas.H"
#include "rPolynomial.H"
#include "perfectFluid.H"
#include "adiabaticPerfectFluid.H"
#include "rhoConst.H"
#include "hConstThermo.H"
#include "eConstThermo.H"
#include "janafThermo.H"
#include "sensibleEnthalpy.H"
#include "sensibleInternalEnergy.H"
#include "thermo.H"
#include "sutherlandTransport.H"
#include "constTransport.H"
#include "twoSCH4Bfer.H"

#include "tabulatedTransport.H"
#include "hTabulatedThermo.H"
#include "icoTabulated.H"

#include "psiThermo.H"
#include "makeThermo.H"
#include "hePsiThermo.H"
#include "pureMixture.H"

#include "thermoPhysicsTypes.H"

#include "rhoReactionThermo.H"
#include "heRhoThermo.H"
#include "Boussinesq.H"
#include "WLFTransport.H"

#include "homogeneousMixture.H"
#include "inhomogeneousMixture.H"
#include "veryInhomogeneousMixture.H"
#include "multiComponentMixture.H"
#include "reactingMixture.H"
#include "singleStepReactingMixture.H"
#include "singleComponentMixture.H"

#endif // PSITHERMO_H

namespace Foam
{



/* * * * * * * * * * * * * * * * * Enthalpy-based * * * * * * * * * * * * * */

makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    twoSCH4Bfer,
    sensibleEnthalpy,
    hConstThermo,
    perfectGas,
    specie
);

/* * * * * * * * * * * * * * Internal-energy-based * * * * * * * * * * * * * */



makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    twoSCH4Bfer,
    sensibleInternalEnergy,
    eConstThermo,
    perfectGas,
    specie
);


makeThermos
(
    psiThermo,
    hePsiThermo,
    pureMixture,
    twoSCH4Bfer,
    sensibleInternalEnergy,
    hConstThermo,
    perfectGas,
    specie
);



//////////////////////////////////////////////////////////////////////////////


// * * * * * * * * * * * * * * * * *reactingMixture* * * * * * * * * * * * * * * * * * * * //
// * * * * * * * * * * * * * * * * *ANALogSutherlandTransport* * * * * * * * * * * * * * * * * * * * //

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferPengRobinsonGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferincompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BfergasEThermoPhysics
);
makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferPengRobinsonGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferincompressibleGasEThermoPhysics
);

// * * * * * * * * * * * * * * * * *ANALogConst* * * * * * * * * * * * * * * * * * * * //

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstIncompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstrPolFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstAdiabaticFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstIncompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstFluidEThermoPhysics
);



makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstAdiabaticFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    reactingMixture,
    twoSCH4BferConstEThermoPhysics
);


// *******************************************multiComponentMixture****************************** //
// *******************************************ANALogSutherlandTransport****************************** //

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferincompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BfergasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferincompressibleGasEThermoPhysics
);




// *******************************************ANALogConst****************************** //

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstIncompressibleGasHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstrPolFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstAdiabaticFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstIncompressibleGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstFluidEThermoPhysics
);



makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstAdiabaticFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    twoSCH4BferConstEThermoPhysics
);

} 



// ************************************************************************* //
