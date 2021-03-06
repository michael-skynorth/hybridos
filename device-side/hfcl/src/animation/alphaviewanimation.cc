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

#include "animation/alphaviewanimation.h"
#include "view/view.h"

namespace hfcl {

AlphaViewAnimation::AlphaViewAnimation(View* view, int endAlpha)
    :ViewAnimation(view, MGEFF_INT)
{
    setEndValue(&endAlpha);
}

AlphaViewAnimation::~AlphaViewAnimation()
{
}

void AlphaViewAnimation::setProperty(int id, void* value)
{
    if (NULL == m_view) {
        return;
    }
    //m_view->setAlpha(*(int*)value);

    m_view->updateView();
}

void AlphaViewAnimation::onStart()
{
    if (NULL != m_view) {
        //int opacity = m_view->alpha();
        //setStartValue(&opacity);
    }
}

} // namespace hfcl

