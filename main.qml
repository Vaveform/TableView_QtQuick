import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.0
import tableModel 1.0

ApplicationWindow {
    id: appWindow

    visible: true
    title: "Table"
    property int margin: 5
    width: mainLayout.implicitWidth + 200 * margin
    height: mainLayout.implicitHeight + 100 * margin
    FileDialog{
        id: filedialog
        title: "Please choose text file"
        nameFilters: ["Text files (*.txt)"]
        // From home directory
        folder: shortcuts.home
        onAccepted: {
            console.log("Chosen: " + filedialog.fileUrl)
            pathfield.text = filedialog.fileUrl
            pathfield.readOnly = true
            tablemodel.readTextFile(pathfield.text)
        }
        onRejected: {
            console.log("File not selected")
        }
    }
    ColumnLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: appWindow.margin
        RowLayout {
            id: rowLayout
            anchors.fill: parent
            TextField {
                id: pathfield
                placeholderText: "Enter path to txt file"
                Layout.fillWidth: true
            }
            Button {
                text: "Select Path"
                onClicked: filedialog.open()
            }
        }
        TableView{
            id: tableview
            Layout.fillHeight: true
            Layout.fillWidth: true
            clip: true
            visible: true
            model: TableViewModel{
                id:tablemodel
            }
            TableViewColumn { role: "id"; title: "Id"; width: tableview.width / 3; resizable: false }
            TableViewColumn { role: "name"; title: "User Names"; width: tableview.width / 3; resizable: false}
            TableViewColumn { role: "phone"; title: "Phone Numbers"; width: tableview.width / 3; resizable: false }

        }
    }
}
