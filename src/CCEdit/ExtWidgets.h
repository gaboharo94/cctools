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

#ifndef _EXTWIDGETS_H
#define _EXTWIDGETS_H

#include <QTabWidget>
#include <QTabBar>

class MidClickClose_TabBar : public QTabBar {
    Q_OBJECT

public:
    MidClickClose_TabBar(QWidget* parent = nullptr) : QTabBar(parent) { }

protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
};

class EditorTabWidget : public QTabWidget {
    Q_OBJECT

public:
    EditorTabWidget(QWidget* parent = nullptr);

Q_SIGNALS:
    void newTabRequested();
};

#endif
