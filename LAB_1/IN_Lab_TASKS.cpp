#include <iostream>
#include <string.h>
using namespace std;

void collectAttendees(char firstEvent[5][30], char secondEvent[5][30], int &attendees1, int &attendees2) {
    cout << "Enter names for First Event (max 5):\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Name of attendee " << (i + 1) << ": ";
        cin >> firstEvent[i];
        if (strlen(firstEvent[i]) == 0) break;
        attendees1++;
    }

    cout << "\nEnter names for Second Event (max 5):\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Name of attendee " << (i + 1) << ": ";
        cin >> secondEvent[i];
        if (strlen(secondEvent[i]) == 0) break;
        attendees2++;
    }
}

bool isAttendeeRegistered(char firstEvent[5][30], char secondEvent[5][30], char* attendeeName, int attendees1, int attendees2) {
    for (int i = 0; i < attendees1; ++i) {
        if (strcmp(firstEvent[i], attendeeName) == 0) return true;
    }
    for (int i = 0; i < attendees2; ++i) {
        if (strcmp(secondEvent[i], attendeeName) == 0) return true;
    }
    return false;
}

int computeTotalFunds(int attendees1, int attendees2) {
    return (attendees1 + attendees2) * 10;
}

void showReversedNames(char event[5][30], char* eventTitle, int attendees) {
    cout << "\nAttendees for " << eventTitle << " in reverse order:\n";
    for (int i = attendees - 1; i >= 0; --i) {
        cout << event[i] << endl;
    }
}

void drawParticipationGraph(int attendees1, int attendees2) {
    cout << "\nEvent Participation Bar Chart:\n";

    int maxAttendees = (attendees1 > attendees2) ? attendees1 : attendees2;

    for (int i = maxAttendees; i > 0; --i) {
        cout << "  ";
        if (i <= attendees1) cout << "*"; else cout << " ";
        cout << "  ";
        if (i <= attendees2) cout << "*"; else cout << " ";
        cout << endl;
    }

    cout << "  --- ---\n";
    cout << "  E1  E2\n";
}

int main() {
    char firstEvent[5][30];
    char secondEvent[5][30];
    int attendees1 = 0, attendees2 = 0;

    collectAttendees(firstEvent, secondEvent, attendees1, attendees2);

    char attendeeName[30];
    cout << "\nEnter an attendee's name to verify registration: ";
    cin >> attendeeName;

    if (isAttendeeRegistered(firstEvent, secondEvent, attendeeName, attendees1, attendees2)) {
        cout << attendeeName << " is registered for one of the events.\n";
    } else {
        cout << attendeeName << " is not registered for any of the events.\n";
    }

    int totalFunds = computeTotalFunds(attendees1, attendees2);
    cout << "\nTotal funds collected: $" << totalFunds << endl;

    showReversedNames(firstEvent, "First Event", attendees1);
    showReversedNames(secondEvent, "Second Event", attendees2);

    drawParticipationGraph(attendees1, attendees2);

    return 0;
}
