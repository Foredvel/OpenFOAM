/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2018 OpenFOAM Foundation
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

InClass
    Foam::psiChemistryModel

Description
    Creates chemistry model instances templated on the type of thermodynamics

\*---------------------------------------------------------------------------*/

#include "makeChemistryModel.H"

#include "psiReactionThermo.H"
#include "rhoReactionThermo.H"

#include "StandardChemistryModel.H"
#include "TDACChemistryModel.H"
#include "thermoPhysicsTypesTwoS.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferGasHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferPengRobinsonGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferPengRobinsonGasHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferincompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferincompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BfergasEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BfergasEThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferPengRobinsonGasEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferPengRobinsonGasEThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferincompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferincompressibleGasEThermoPhysics
    );


    // ************************************************************************* //

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstGasHThermoPhysics
    );
    
    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstIncompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstIncompressibleGasHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstrPolFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstrPolFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstAdiabaticFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstAdiabaticFluidHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstHThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstGasEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstGasEThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstIncompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstIncompressibleGasEThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstFluidEThermoPhysics
    );


    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstAdiabaticFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstAdiabaticFluidEThermoPhysics
    );

    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstEThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BferConstEThermoPhysics
    );
    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BfericoPoly8HThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BfericoPoly8HThermoPhysics
    );
    makeChemistryModelType
    (
        StandardChemistryModel,
        rhoReactionThermo,
        twoSCH4BfericoPoly8EThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        rhoReactionThermo,
        twoSCH4BfericoPoly8EThermoPhysics
    );
    
    makeChemistryModelType
    (
        StandardChemistryModel,
        psiReactionThermo,
        twoSCH4BferGasHThermoPhysics
    );

    makeChemistryModelType
    (
        TDACChemistryModel,
        psiReactionThermo,
        twoSCH4BferGasHThermoPhysics
    );


}

// ************************************************************************* //
