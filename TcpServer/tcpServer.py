# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.5.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(400, 300)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setObjectName("centralWidget")
        self.Pesan = QtWidgets.QLineEdit(self.centralWidget)
        self.Pesan.setGeometry(QtCore.QRect(50, 230, 251, 22))
        self.Pesan.setObjectName("Pesan")
        self.Send = QtWidgets.QPushButton(self.centralWidget)
        self.Send.setGeometry(QtCore.QRect(310, 230, 51, 22))
        self.Send.setObjectName("Send")
        self.KotakPesan = QtWidgets.QTextEdit(self.centralWidget)
        self.KotakPesan.setGeometry(QtCore.QRect(50, 60, 301, 161))
        self.KotakPesan.setObjectName("KotakPesan")
        self.label = QtWidgets.QLabel(self.centralWidget)
        self.label.setGeometry(QtCore.QRect(50, 31, 50, 16))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralWidget)
        self.label_2.setGeometry(QtCore.QRect(110, 31, 21, 16))
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralWidget)
        self.label_3.setGeometry(QtCore.QRect(210, 31, 33, 16))
        self.label_3.setObjectName("label_3")
        self.IP = QtWidgets.QLineEdit(self.centralWidget)
        self.IP.setGeometry(QtCore.QRect(130, 31, 71, 22))
        self.IP.setObjectName("IP")
        self.Port = QtWidgets.QLineEdit(self.centralWidget)
        self.Port.setGeometry(QtCore.QRect(238, 31, 51, 22))
        self.Port.setObjectName("Port")
        self.Btn_Start = QtWidgets.QPushButton(self.centralWidget)
        self.Btn_Start.setGeometry(QtCore.QRect(299, 31, 51, 22))
        self.Btn_Start.setObjectName("Btn_Start")
        MainWindow.setCentralWidget(self.centralWidget)
        self.menuBar = QtWidgets.QMenuBar(MainWindow)
        self.menuBar.setGeometry(QtCore.QRect(0, 0, 400, 19))
        self.menuBar.setObjectName("menuBar")
        MainWindow.setMenuBar(self.menuBar)
        self.statusBar = QtWidgets.QStatusBar(MainWindow)
        self.statusBar.setObjectName("statusBar")
        MainWindow.setStatusBar(self.statusBar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.Send.setText(_translate("MainWindow", "Send"))
        self.label.setText(_translate("MainWindow", "TextBox"))
        self.label_2.setText(_translate("MainWindow", "IP :"))
        self.label_3.setText(_translate("MainWindow", "Port :"))
        self.Btn_Start.setText(_translate("MainWindow", "Start"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

