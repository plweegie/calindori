import QtQuick 2.7
import QtQuick.Controls 2.0 as Controls2

Controls2.ToolButton {
    id: root

    property string selectorTimeZone
    property string selectorTitle

    text: "Time zone"

    onClicked: {
        timeZonePickerSheet.timeZone = selectorTimeZone;
        timeZonePickerSheet.open();
    }

    TimeZonePickerSheet {
        id: timeZonePickerSheet

        headerText: root.selectorTitle

        onTimeZonePicked: {
            root.selectorTimeZone = timeZonePickerSheet.timeZone;
        }
    }
}
