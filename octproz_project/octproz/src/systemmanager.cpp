/**
**  This file is part of OCTproZ.
**  OCTproZ is an open source software for processig of optical
**  coherence tomography (OCT) raw data.
**  Copyright (C) 2019-2022 Miroslav Zabic
**
**  OCTproZ is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program. If not, see http://www.gnu.org/licenses/.
**
****
** Author:	Miroslav Zabic
** Contact:	zabic
**			at
**			spectralcode.de
****
**/

#include "systemmanager.h"

SystemManager::SystemManager(QObject *parent) : QObject(parent)
{

}

void SystemManager::addSystem(AcquisitionSystem* system){
	if(system != nullptr){
		if(!systems.contains(system)){
			this->systems.append(system);
			this->systemNames.append(system->getName());
			this->systemNames.last().detach(); //force deep copy of appended system name to avoid possible problems if plugin lives at some point in a thread
		}
	}
}

AcquisitionSystem* SystemManager::getSystemByName(QString name){
	return this->systems.at(this->systemNames.indexOf(name));
}
