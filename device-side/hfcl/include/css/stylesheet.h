/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef HFCL_CSS_STYLESHEET_H_
#define HFCL_CSS_STYLESHEET_H_

#include "../common/common.h"
#include "../common/stlalternative.h"
#include "propertyvalue.h"

#define PPT_FLAG_INHERITED     0x00000001

namespace hfcl {

class StyleSheet {
public:
    StyleSheet () : m_ssid (0) {}
    StyleSheet (int ssid) : m_ssid (ssid) {}
    virtual ~StyleSheet () {}

    virtual bool getProperty (PropertyIds pid, DWORD32 *value,
            HTData *data = NULL) = 0;
    virtual bool setProperty (PropertyIds pid, DWORD32 value,
            HTData data = 0) = 0;

protected:
    int m_ssid;
};

namespace css {

} // namespace css

} // namespace hfcl

#endif /* HFCL_CSS_STYLESHEET_H_ */
