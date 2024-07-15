#include <iostream>
#include "odataConsumer.h"

using namespace std;

string odataConsumer::parseData(string data) {
    if (data == "")
    {
        return "No data to parse for Odata consumer!";
    }
    

    string str = "";
    int indentCount = 0;

    // Removing the first <section> tag
    data = data.substr(9, data.length());

    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] == '<')
        {
            if (data[i + 1] == '/')
            {
                indentCount--;
            }
            else
            {
                indentCount++;
            }
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

string odataConsumer::RemoveTags(string str) {

    string substringToReplace = "<section>";
    string replacement = "";

    size_t pos = str.find(substringToReplace);

    while (pos != string::npos) {
        str.replace(pos, substringToReplace.length(), replacement);
        pos = str.find(substringToReplace, pos + replacement.length());
    }

    substringToReplace = "</section>";

    pos = str.find(substringToReplace);

    while (pos != string::npos) {
        str.replace(pos, substringToReplace.length(), replacement);
        pos = str.find(substringToReplace, pos + replacement.length());
    }

    return str;
}

string odataConsumer::RemoveEmptyLines(string data) {
    string str = "";

    size_t prevPos = 0;  // Store the position of the last non-empty line

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


