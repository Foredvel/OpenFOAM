/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2017 OpenFOAM Foundation
    Copyright (C) 2018-2023 OpenCFD Ltd.
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
    Foam::thermoPhysicsTypes

Description
    Type definitions for thermo-physics models

\*---------------------------------------------------------------------------*/

#ifndef thermoPhysicsTypesTwoS_H
#define thermoPhysicsTypesTwoS_H

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

#include "icoPolynomial.H"
#include "hPolynomialThermo.H"
#include "polynomialTransport.H"

#include "tabulatedTransport.H"
#include "hTabulatedThermo.H"
#include "icoTabulated.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    // * * * * * * * * * * * * * * * * *ANALogSutherlandTransport* * * * * * * * * * * * * * * * * * * * //
    // * * * * * * * * * * * * * * * * *sensibleEnthalpy * * * * * * * * * * * * * * * * * * * * //
    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                perfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > twoSCH4BferGasHThermoPhysics;

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                PengRobinsonGas<specie>
            >,
            sensibleEnthalpy
        >
    > twoSCH4BferPengRobinsonGasHThermoPhysics;

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > twoSCH4BferincompressibleGasHThermoPhysics;

    
    // * * * * * * * * * * * * * * * * *sensibleInternalEnergy * * * * * * * * * * * * * * * * * * * * //

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                perfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > twoSCH4BfergasEThermoPhysics;


    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                PengRobinsonGas<specie>
            >,
            sensibleInternalEnergy
        >
    > twoSCH4BferPengRobinsonGasEThermoPhysics;

    
    
    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            janafThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > twoSCH4BferincompressibleGasEThermoPhysics;

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    // * * * * * * * * * * * * * * * * *ANALogConstTransport* * * * * * * * * * * * * * * * * * * * //
    // * * * * * * * * * * * * * * * * *sensibleEnthalpy * * * * * * * * * * * * * * * * * * * * //
    

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                perfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > twoSCH4BferConstGasHThermoPhysics;//constGasHThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleEnthalpy
        >
    > twoSCH4BferConstIncompressibleGasHThermoPhysics;//constIncompressibleGasHThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                perfectFluid<specie>
            >,
            sensibleEnthalpy
        >
    >
    twoSCH4BferConstFluidHThermoPhysics;//constFluidHThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                rPolynomial<specie>
            >,
            sensibleEnthalpy
        >
    >
    twoSCH4BferConstrPolFluidHThermoPhysics;//constrPolFluidHThermoPhysics
    
    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                adiabaticPerfectFluid<specie>
            >,
            sensibleEnthalpy
        >
    >
    twoSCH4BferConstAdiabaticFluidHThermoPhysics;//constAdiabaticFluidHThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            hConstThermo
            <
                rhoConst<specie>
            >,
            sensibleEnthalpy
        >
    >
    twoSCH4BferConstHThermoPhysics;//constHThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            eConstThermo
            <
                perfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > twoSCH4BferConstGasEThermoPhysics;//constGasEThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            eConstThermo
            <
                incompressiblePerfectGas<specie>
            >,
            sensibleInternalEnergy
        >
    > twoSCH4BferConstIncompressibleGasEThermoPhysics;//constIncompressibleGasEThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            eConstThermo
            <
                perfectFluid<specie>
            >,
            sensibleInternalEnergy
        >
    >
    twoSCH4BferConstFluidEThermoPhysics;//constFluidEThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            eConstThermo
            <
                adiabaticPerfectFluid<specie>
            >,
            sensibleInternalEnergy
        >
    >
    twoSCH4BferConstAdiabaticFluidEThermoPhysics;//constAdiabaticFluidEThermoPhysics

    typedef
    twoSCH4Bfer
    <
        species::thermo
        <
            eConstThermo
            <
                rhoConst<specie>
            >,
            sensibleInternalEnergy
        >
    >
    twoSCH4BferConstEThermoPhysics;//constEThermoPhysics


}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
