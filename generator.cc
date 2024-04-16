#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1);
	//gParticleGun = new G4ParticleGun(1);
	
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle1 = particleTable->FindParticle("proton");
	//G4ParticleDefinition *particle2 = particleTable->FindParticle("e-");
	
	G4ThreeVector pos1(0., 0., -0.25*m);
	G4ThreeVector mom1(0., 0., 1.);
	
	//G4ThreeVector pos2(0., 0., 0.1);
	//G4ThreeVector mom2(0., 0., -1.);
	
	fParticleGun->SetParticlePosition(pos1);
	fParticleGun->SetParticleMomentumDirection(mom1);
	fParticleGun->SetParticleMomentum(100.*MeV);
	fParticleGun->SetParticleDefinition(particle1);
	
	//gParticleGun->SetParticlePosition(pos2);
	//gParticleGun->SetParticleMomentumDirection(mom2);
	//gParticleGun->SetParticleMomentum(10.*MeV);
	//gParticleGun->SetParticleDefinition(particle2);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
	//delete gParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	//G4ParticleDefinition *particle1 = fParticleGun->GetParticleDefinition();
	//G4ParticleDefinition *particle2 = gParticleGun->GetParticleDefinition();
	
	fParticleGun->GeneratePrimaryVertex(anEvent);
	//gParticleGun->GeneratePrimaryVertex(anEvent);
}
