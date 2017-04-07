/* This file is part of the KDE project
 *
 * Copyright 2017 Boudewijn Rempt <boud@valdyas.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

// Own
#include "TextNGShapePlugin.h"

// KDE
#include <kpluginfactory.h>

// Calligra libs
#include <KoShapeRegistry.h>
#include <KoToolRegistry.h>

// TextNGShape
#include "TextNGToolFactory.h"
#include "TextNGShapeFactory.h"

K_PLUGIN_FACTORY_WITH_JSON(TextNGShapePluginFactory, "krita_shape_textng.json", registerPlugin<TextNGShapePlugin>();)

TextNGShapePlugin::TextNGShapePlugin(QObject *parent, const QVariantList &)
    : QObject(parent)
{
    KoToolRegistry::instance()->add(new TextNGToolFactory());
    KoShapeRegistry::instance()->add(new TextNGShapeFactory());
}

#include <TextNGShapePlugin.moc>
