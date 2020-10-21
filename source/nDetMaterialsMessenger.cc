
#include <iostream>

#include "nDetMaterialsMessenger.hh"
#include "nDetConstruction.hh"

#include "G4Material.hh"
#include "G4UIcommand.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWith3Vector.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4SystemOfUnits.hh"

void nDetMaterialsMessenger::addAllCommands()
{
	addDirectory("/nDet/materials/", "Material controls");

	addCommand(new G4UIcmdWithoutParameter("/nDet/materials/listAll", this));
	addGuidance("Print all pre-defined materials, visual attributes, and optical surfaces which are available for use");

	addCommand(new G4UIcmdWithoutParameter("/nDet/materials/listMaterials", this));
	addGuidance("Print all pre-defined materials which are available for use");

	addCommand(new G4UIcmdWithoutParameter("/nDet/materials/listVisAttributes", this));
	addGuidance("Print all pre-defined visual attributes which are available for use");

	addCommand(new G4UIcmdWithoutParameter("/nDet/materials/listOptSurfaces", this));
	addGuidance("Print all pre-defined optical surfaces which are available for use");

	addCommand(new G4UIcmdWithAString("/nDet/materials/searchForMaterial", this));
	addGuidance("Search for a material in the list of pre-defined NEXTSim materials OR in the NIST database");

	addCommand(new G4UIcmdWithAString("/nDet/materials/readMaterial", this));
	addGuidance("Construct a new material by reading an input file");

	addCommand(new G4UIcmdWithAString("/nDet/materials/printMaterial", this));
	addGuidance("Print parameters for a defined NEXTSim construction material");

	
}

void nDetMaterialsMessenger::SetNewChildValue(G4UIcommand *command, G4String newValue)
{
	size_t index;
	if (!findCommand(command, newValue, index))
		return;

	if (index == 0)
	{
		fMaterials->listMaterials();
		fMaterials->listVisAttributes();
		fMaterials->listOptSurfaces();
	}
	else if (index == 1)
	{
		fMaterials->listMaterials();
	}
	else if (index == 2)
	{
		fMaterials->listVisAttributes();
	}
	else if (index == 3)
	{
		fMaterials->listOptSurfaces();
	}
	else if (index == 4)
	{
		if (fMaterials->searchForMaterial(newValue))
			std::cout << "Found material named \"" << newValue << "\" in material list\n";
	}
	else if (index == 5)
	{
		fMaterials->buildNewMaterial(newValue);
	}
	else if (index == 6)
	{
		fMaterials->printMaterial(newValue);
	}
	
}
