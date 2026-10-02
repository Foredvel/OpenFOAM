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

template<class Thermo>
Foam::twoSCH4Bfer<Thermo>::twoSCH4Bfer(const Foam::dictionary& dict)
:
    Thermo(dict) 
{
    
    const Foam::dictionary& transportDict = dict.subDict("transport");

    mu_    = dict.subDict("transport").get<scalar>("mu");
    T0_ = dict.subDict("transport").get<scalar>("T0");
    alpha_ = dict.subDict("transport").get<scalar>("muExponent");

    const bool foundPr    = transportDict.found("Pr");
    const bool foundKappa = transportDict.found("kappa");

    if (foundPr == foundKappa)
    {
        FatalIOErrorInFunction(dict)
            << "Either Pr or kappa must be specified, but not both."
            << exit(FatalIOError);
    }

    constPr_ = foundPr;
    if (constPr_)
    {
        transportDict.lookup("Pr") >> rPr_;
        rPr_ = 1.0/rPr_;
        kappa_ = NAN;
    }
    else
    {
        transportDict.lookup("kappa") >> kappa_;
        rPr_ = NAN;
    }
}

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

template<class Thermo>
void Foam::twoSCH4Bfer<Thermo>::twoSCH4Bfer::write(Ostream& os) const
{
   
    os.beginBlock(this->name());

    Thermo::write(os);

    // Entries in dictionary format
    {
        os.beginBlock("transport");
        os.writeEntry("mu", mu_);
        os.writeEntry("alpha", alpha_);
        os.writeEntry("T0", T0_);
        os.endBlock();

        if (constPr_)
        {
            os.writeEntry("Pr", rPr_);
        }
        else
        {
            os.writeEntry("kappa", kappa_);
        }
    }

    os.endBlock();

}


// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

template<class Thermo>
Foam::Ostream& Foam::operator<<(Ostream& os, const twoSCH4Bfer<Thermo>& ct)
{
    ct.write(os);
    return os;
}

// ************************************************************************* //
