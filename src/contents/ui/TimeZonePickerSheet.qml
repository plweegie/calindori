import QtQuick 2.7
import QtQuick.Controls 2.0 as Controls2
import QtQuick.Layouts 1.3
import org.kde.kirigami 2.0 as Kirigami

Kirigami.OverlaySheet {
    id: timeZonePickerSheet

    property string headerText
    property string timeZone

    signal timeZonePicked

    header: Kirigami.Heading {
        level: 1
        text: timeZonePickerSheet.headerText
    }

    contentItem: ListView {
        id: timeZoneList
        model: _timeZoneModel
        anchors.fill: parent

        delegate: Kirigami.BasicListItem {
            reserveSpaceForIcon: false
            label: model.name

            onClicked: root.timeZone = model.name;
        }
    }

    footer: RowLayout {

        Item {
            Layout.fillWidth: true
        }

        Controls2.ToolButton {
            text: i18n("OK")
            onClicked: {
                timeZonePickerSheet.timeZonePicked();
                timeZonePickerSheet.close();
            }
        }

        Controls2.ToolButton {
            text: i18n("Cancel")
            onClicked: {
                timeZonePickerSheet.close();
            }
        }
    }
}
