//  OpenVPN 3 Linux client -- Next generation OpenVPN client
//
//  Copyright (C) 2018      OpenVPN, Inc. <sales@openvpn.net>
//  Copyright (C) 2018      David Sommerseth <davids@openvpn.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as
//  published by the Free Software Foundation, version 3 of the
//  License.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

/**
 * @file   fetch-avail-config-paths.cpp
 *
 * @brief  Prints all available configuration paths imported to the
 *         configuration manager (openvpn3-service-configmgr)
 */

#include <iostream>

#include "dbus/core.hpp"
#include "configmgr/proxy-configmgr.hpp"

int main(int argc, char **argv)
{
    OpenVPN3ConfigurationProxy cfgproxy(G_BUS_TYPE_SYSTEM,
                                        OpenVPN3DBus_rootp_configuration);
    for (auto& cfg : cfgproxy.FetchAvailableConfigs())
    {
        std::cout << cfg << std::endl;
    }
    return 0;
}
