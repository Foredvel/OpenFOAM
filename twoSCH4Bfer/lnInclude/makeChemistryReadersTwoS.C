/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2015 OpenFOAM Foundation
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

\*---------------------------------------------------------------------------*/

#include "makeReactionThermo.H"
#include "thermoPhysicsTypesTwoS.H"

#include "chemistryReader.H"
#include "foamChemistryReader.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Solid chemistry readers based on sensibleEnthalpy
makeChemistryReader(twoSCH4BferGasHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferGasHThermoPhysics);


makeChemistryReader(twoSCH4BferPengRobinsonGasHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferPengRobinsonGasHThermoPhysics);

makeChemistryReader(twoSCH4BferincompressibleGasHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferincompressibleGasHThermoPhysics);

makeChemistryReader(twoSCH4BfergasEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BfergasEThermoPhysics);

makeChemistryReader(twoSCH4BferPengRobinsonGasEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferPengRobinsonGasEThermoPhysics);

makeChemistryReader(twoSCH4BferincompressibleGasEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferincompressibleGasEThermoPhysics);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

makeChemistryReader(twoSCH4BferConstGasHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstGasHThermoPhysics);

makeChemistryReader(twoSCH4BferConstIncompressibleGasHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstIncompressibleGasHThermoPhysics);

makeChemistryReader(twoSCH4BferConstFluidHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstFluidHThermoPhysics);

makeChemistryReader(twoSCH4BferConstrPolFluidHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstrPolFluidHThermoPhysics);

makeChemistryReader(twoSCH4BferConstAdiabaticFluidHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstAdiabaticFluidHThermoPhysics);

makeChemistryReader(twoSCH4BferConstHThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstHThermoPhysics);

makeChemistryReader(twoSCH4BferConstGasEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstGasEThermoPhysics);

makeChemistryReader(twoSCH4BferConstIncompressibleGasEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstIncompressibleGasEThermoPhysics);

makeChemistryReader(twoSCH4BferConstFluidEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstFluidEThermoPhysics);


makeChemistryReader(twoSCH4BferConstAdiabaticFluidEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstAdiabaticFluidEThermoPhysics);

makeChemistryReader(twoSCH4BferConstEThermoPhysics)
makeChemistryReaderType(foamChemistryReader, twoSCH4BferConstEThermoPhysics);




} // End namespace Foam

// ************************************************************************* //
