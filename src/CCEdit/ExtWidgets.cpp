/******************************************************************************
 * This file is part of CCTools.                                              *
 *                                                                            *
 * CCTools is free software: you can redistribute it and/or modify            *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * CCTools is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with CCTools.  If not, see <http://www.gnu.org/licenses/>.           *
 ******************************************************************************/

#include "ExtWidgets.h"

#include <QToolButton>
#include <QMouseEvent>

void MidClickClose_TabBar::mouseReleaseEvent(QMouseEvent* event)
{
    int tab = tabAt(event->pos());
    if (tab >= 0 && event->button() == Qt::MiddleButton)
        emit tabCloseRequested(tab);

    QTabBar::mouseReleaseEvent(event);
}

EditorTabWidget::EditorTabWidget(QWidget* parent)
    : QTabWidget(parent)
{
    setTabBar(new MidClickClose_TabBar(this));

    auto newTabButton = new QToolButton(this);
    newTabButton->setIcon(QIcon(":/res/tab-new-sm.png"));
    newTabButton->setStatusTip(tr("Open a new editor tab"));
    newTabButton->setAutoRaise(true);
    setCornerWidget(newTabButton, Qt::TopLeftCorner);
    setMovable(true);
    setTabsClosable(true);

    connect(newTabButton, &QToolButton::clicked,
            this, &EditorTabWidget::newTabRequested);
}
