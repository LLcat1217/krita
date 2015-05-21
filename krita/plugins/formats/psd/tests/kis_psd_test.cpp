/*
 * Copyright (C) 2009 Boudewijn Rempt <boud@valdyas.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "kis_psd_test.h"


#include <QTest>
#include <QCoreApplication>

#include <qtest_kde.h>

#include "filestest.h"

#ifndef FILES_DATA_DIR
#error "FILES_DATA_DIR not set. A directory with the data used for testing the importing of files in krita"
#endif

#include <KoPattern.h>
#include "kis_group_layer.h"
#include "kis_psd_layer_style.h"


void KisPSDTest::testFiles()
{
    TestUtil::testFiles(QString(FILES_DATA_DIR) + "/sources", QStringList());
}

void KisPSDTest::testOpening()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "testing_psd_ls.psd");

    QScopedPointer<KisDocument> doc(qobject_cast<KisDocument*>(KisPart::instance()->createDocument()));

    KisImportExportManager manager(doc.data());
    manager.setBatchMode(true);

    KisImportExportFilter::ConversionStatus status;
    QString s = manager.importDocument(sourceFileInfo.absoluteFilePath(), QString(),
                                       status);
    qDebug() << s;

    Q_ASSERT(doc->image());
}

QSharedPointer<KisDocument> openPsdDocument(const QFileInfo &fileInfo)
{
    QSharedPointer<KisDocument> doc(qobject_cast<KisDocument*>(KisPart::instance()->createDocument()));

    KisImportExportManager manager(doc.data());
    manager.setBatchMode(true);

    KisImportExportFilter::ConversionStatus status;
    QString s = manager.importDocument(fileInfo.absoluteFilePath(), QString(),
                                       status);

    return doc;
}

void KisPSDTest::testTransparencyMask()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "sources/masks.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());

    QImage result = doc->image()->projection()->convertToQImage(0, doc->image()->bounds());
    QVERIFY(TestUtil::checkQImageExternal(result, "psd_test", "transparency_masks", "kiki_single"));

    doc->setBackupFile(false);
    doc->setOutputMimeType("image/vnd.adobe.photoshop");
    QFileInfo dstFileInfo(QDir::currentPath() + QDir::separator() + "test_tmask.psd");
    bool retval = doc->saveAs(KUrl(dstFileInfo.absoluteFilePath()));
    QVERIFY(retval);

    {
        QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
        QVERIFY(doc->image());

        QImage result = doc->image()->projection()->convertToQImage(0, doc->image()->bounds());
        QVERIFY(TestUtil::checkQImageExternal(result, "psd_test", "transparency_masks", "kiki_single"));

        QVERIFY(doc->image()->root()->lastChild());
        QVERIFY(doc->image()->root()->lastChild()->firstChild());
        QVERIFY(doc->image()->root()->lastChild()->firstChild()->inherits("KisTransparencyMask"));
    }
}

void KisPSDTest::testOpenGrayscaleMultilayered()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "sources/gray.psd");
    //QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "sources/100x100gray8.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());
}

void KisPSDTest::testOpenGroupLayers()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "group_layers.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());

    KisNodeSP node = TestUtil::findNode(doc->image()->root(), "Group 1 PT");
    KisGroupLayer *group = dynamic_cast<KisGroupLayer*>(node.data());
    QVERIFY(group);

    QVERIFY(group->passThroughMode());
}

void KisPSDTest::testOpenLayerStyles()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "testing_psd_ls.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());

    KisLayerSP layer = dynamic_cast<KisLayer*>(doc->image()->root()->lastChild().data());
    QVERIFY(layer->layerStyle());
    QVERIFY(layer->layerStyle()->dropShadow());
    QVERIFY(layer->layerStyle()->dropShadow()->effectEnabled());
}

void KisPSDTest::testOpenLayerStylesWithPattern()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "test_ls_pattern.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());

    KisLayerSP layer = dynamic_cast<KisLayer*>(doc->image()->root()->lastChild().data());
    QVERIFY(layer->layerStyle());
    QVERIFY(layer->layerStyle()->patternOverlay());
    QVERIFY(layer->layerStyle()->patternOverlay()->effectEnabled());
    QVERIFY(layer->layerStyle()->patternOverlay()->pattern());
    QVERIFY(layer->layerStyle()->patternOverlay()->pattern()->valid());
}

void KisPSDTest::testOpenLayerStylesWithPatternMulti()
{
    QFileInfo sourceFileInfo(QString(FILES_DATA_DIR) + QDir::separator() + "test_ls_pattern_multi.psd");

    Q_ASSERT(sourceFileInfo.exists());

    QSharedPointer<KisDocument> doc = openPsdDocument(sourceFileInfo);
    QVERIFY(doc->image());

    KisLayerSP layer = dynamic_cast<KisLayer*>(doc->image()->root()->lastChild().data());
    QVERIFY(layer->layerStyle());

    QVERIFY(layer->layerStyle()->patternOverlay());
    QVERIFY(layer->layerStyle()->patternOverlay()->effectEnabled());
    QVERIFY(layer->layerStyle()->patternOverlay()->pattern());
    QVERIFY(layer->layerStyle()->patternOverlay()->pattern()->valid());

    QVERIFY(layer->layerStyle()->stroke());
    QVERIFY(layer->layerStyle()->stroke()->effectEnabled());
    QVERIFY(layer->layerStyle()->stroke()->pattern());
    QVERIFY(layer->layerStyle()->stroke()->pattern()->valid());
}


QTEST_KDEMAIN(KisPSDTest, GUI)

#include "kis_psd_test.moc"
