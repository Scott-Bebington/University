#include "jsonConsumer.h"
#include <iostream>

using namespace std;

string jsonConsumer::parseData(string data) {

    if (data == "")
    {
        return "No data to parse for JSON consumer!";
    }

    string str = "";
    int indentCount = 0;

    // Removing the first <section> tag
    data = data.substr(1, data.length());

    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] == '{')
        {
            indentCount++;
        }
        else if (data[i] == '}')
        {
            indentCount--;
        }

        if (data[i] == '\n')
        {
            str += data[i];
            for (int j = 0; j < indentCount; j++)
            {
                str += "\t";
            }
        }
        else
        {
            str += data[i];
        }
    }

    // Removing all the section tags  
    string removedTags = RemoveTags(str);
    return RemoveEmptyLines(removedTags);
}

string jsonConsumer::RemoveTags(string str) {

    string substringToReplace = "{";

    size_t pos = str.find(substringToReplace);

    while (pos != string::npos) {
        str.replace(pos, 1, "");
        pos = str.find(substringToReplace, pos);
    }

    substringToReplace = "}";

    pos = str.find(substringToReplace);

    while (pos != string::npos) {
        str.replace(pos, 1, "");
        pos = str.find(substringToReplace, pos);
    }

    return str;
}

string jsonConsumer::RemoveEmptyLines(string data) {
    string str = "";

    int prevPos = 0;

    for (size_t i = 0; i < data.length(); i++) {
        if (data[i] == '\n') {
            // Extract the current line
            string line = data.substr(prevPos, i - prevPos);

            // Trim the line to remove leading and trailing whitespace
            size_t firstNonSpace = line.find_first_not_of(" \t");

            if (firstNonSpace != string::npos) {
                // If the line contains non-whitespace characters, add it to the result
                str += line + "\n";
            }

            prevPos = i + 1;  // Update the previous position for the next line
        }
    }

    // Add the last line (after the loop ends)
    str += data.substr(prevPos);

    return str;
}



