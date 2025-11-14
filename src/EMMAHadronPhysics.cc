//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: EMMAHadronPhysics.cc,v 1.9 2009-11-21 01:00:19 perl Exp $
// --------------------------------------------------------------
//
// 09-Oct-2003 Hadron Physics List with Parameterization Model by T. Koi
// 12-Oct-2003 Bug Fixed (KaonMinus) by T. Koi

#include "EMMAHadronPhysics.hh"

#include "globals.hh"
#include "G4ios.hh"

#include <iomanip>   

#include "G4CascadeInterface.hh"
#include "G4TheoFSGenerator.hh"
#include "G4FTFModel.hh"

#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4NeutronCaptureProcess.hh"
#include "G4NeutronFissionProcess.hh"
#include "G4NeutronRadCapture.hh"
#include "G4NeutronHPFission.hh"

#include "G4PhysListFactory.hh"

EMMAHadronPhysics::EMMAHadronPhysics(const G4String& name)
                   :  G4VPhysicsConstructor(name)
{
}

EMMAHadronPhysics::~EMMAHadronPhysics()
{
}

#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"

#include "G4ProcessManager.hh"

void EMMAHadronPhysics::ConstructProcess()
{
//   G4ProcessManager * pManager = 0;
//
//
//   // Proton Physics
//   pManager = G4Proton::Proton()->GetProcessManager();
//
//   // add process
//   G4HadronElasticProcess* thepElasticProcess = new G4HadronElasticProcess();
//   G4HadronElastic* thepElasticModel = new G4HadronElastic();
//
//   thepElasticProcess->RegisterMe(thepElasticModel);
//   pManager->AddDiscreteProcess(thepElasticProcess);
//
//
//
//
//   G4HadronInelasticProcess* theProtonInelasticProcess = new G4HadronInelasticProcess("protonInelastic", G4Proton::Proton()); 
//   G4CascadeInterface* theProtonLEPModel = new G4CascadeInterface();
//   theProtonInelasticProcess->RegisterMe(theProtonLEPModel);
//   
//   //theProtonInelasticProcess->RegisterMe(theProtonHEPModel);
//   pManager->AddDiscreteProcess(theProtonInelasticProcess);
//
//   G4VProcess* thepMultipleScattering = new G4hMultipleScattering();
//   G4VProcess* thepIonisation        = new G4hIonisation();
//
//   pManager->AddProcess(thepIonisation);
//   pManager->AddProcess(thepMultipleScattering);
//
//   // set ordering for AlongStepDoIt
//   pManager->SetProcessOrdering(thepMultipleScattering, idxAlongStep,1);
//   pManager->SetProcessOrdering(thepIonisation,        idxAlongStep,2);
//   // 
//   // set ordering for PostStepDoIt
//   pManager->SetProcessOrdering(thepMultipleScattering, idxPostStep,1);
//   pManager->SetProcessOrdering(thepIonisation,        idxPostStep,2);
//
//
//
//   // neutron Physics
//   pManager = G4Neutron::Neutron()->GetProcessManager();
//
//   // add process
//   G4HadronElasticProcess* thenElasticProcess 
//     = new G4HadronElasticProcess();
//   //G4LElastic* thenElasticModel = new G4LElastic();
//   G4HadronElastic* thenElasticModel = new G4HadronElastic();
//   thenElasticProcess->RegisterMe(thenElasticModel);
//   pManager->AddDiscreteProcess(thenElasticProcess);
//
//   //G4NeutronInelasticProcess* theNeutronInelasticProcess = new G4NeutronInelasticProcess(); 
//   G4HadronInelasticProcess* theNeutronInelasticProcess = new G4HadronInelasticProcess("neutronInelastic", G4Neutron::Neutron());
//   
//   //G4LENeutronInelastic* theNeutronLEPModel = new G4LENeutronInelastic();
//   G4CascadeInterface* theNeutronLEPModel = new G4CascadeInterface();
//   theNeutronLEPModel->SetMinEnergy(0.0);
//   theNeutronLEPModel->SetMaxEnergy(10*CLHEP::GeV);
//
//   //G4HENeutronInelastic* theNeutronHEPModel = new G4HENeutronInelastic();
//   theNeutronInelasticProcess->RegisterMe(theNeutronLEPModel);
//   //theNeutronInelasticProcess->RegisterMe(theNeutronHEPModel);
//   pManager->AddDiscreteProcess(theNeutronInelasticProcess);
//
//   //G4NeutronFissionProcess* thenFission = new G4NeutronFissionProcess();
//   G4NeutronFissionProcess* thenFission = new G4NeutronFissionProcess();
//   //G4LFission* thenFissionModel = new G4LFission();
//   G4NeutronHPFission* thenFissionModel = new G4NeutronHPFission();
//   thenFission->RegisterMe(thenFissionModel);
//   pManager->AddDiscreteProcess(thenFission);
//
//   //G4HadronCaptureProcess* thenCapture = new G4HadronCaptureProcess();
//   G4NeutronCaptureProcess* thenCapture = new G4NeutronCaptureProcess();
//   //G4LCapture* thenCaptureModel = new G4LCapture();
//   G4NeutronRadCapture* thenCaptureModel = new G4NeutronRadCapture();
//   thenCapture->RegisterMe(thenCaptureModel);
//   pManager->AddDiscreteProcess(thenCapture);

}
