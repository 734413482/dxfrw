#include "DxfRW.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include "dx_iface.h"
#include "dx_data.h"
#include "qdebug.h"
#include "RS_Document.h"
#include "rs_graphic.h"
#include "qg_filedialog.h"
#ifndef S_ISDIR
#define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

void read() {
	QString fileName = "G:\\autocad_2000.dwg";
	RS_Document* document;
	document = new RS_Graphic();

	RS_Graphic graphic;
	graphic.getEntityList();
	graphic.getBlockList();
	graphic.getLayerList();
	graphic.getVariableDict();

	document->newDoc();
	bool ret = false;
	if (document && !fileName.isEmpty()) {
		document->newDoc();
		// cosmetics..
		// RVT_PORT qApp->processEvents(1000);
		qApp->processEvents(QEventLoop::AllEvents, 1000);

		ret = document->open(fileName, RS2::FormatDXFRW);
		if (ret) {
			//QString message=tr("Loaded document: ")+fileName;
			//statusBar()->showMessage(message, 2000);

			/////graphicView->redraw();
		}
		else {
			qDebug() << "QC_MDIWindow::slotFileOpen: failed";
		}
	}
	else {
		qDebug() << "QC_MDIWindow::slotFileOpen: cancelled";
		//statusBar()->showMessage(tr("Opening aborted"), 2000);
	}
}
void save() {
	bool ret = false;
	bool cancelled = false;
	RS2::FormatType t = RS2::FormatDXFRW;   //FormatDWG FormatDXFRW
	QString fn = "G:\\dxfdwgfile\\autocad_2002.dxf";
	RS_Document* document;
	document = new RS_Graphic();
	if (document && !fn.isEmpty()) {
		ret = document->saveAs(fn, t, true);
	}
	else {
		// cancel is not an error - returns true
		ret = true;
		cancelled = true;
	}
}
int main()
{
	//QG_GraphicView* graphicView;
	
	read();
	save();
	return 0;
	//QApplication a(argc, argv);
	//QtDxfRW w;
	//w.show();
	//return a.exec();
}
