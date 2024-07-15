
# Accept the file name as input from the cli
our $fileName = $ARGV[0];
# Accept the word to search for as input from the cli
our $wordToSearchFor = $ARGV[1];

# Global variable to store the file contents
our $convertedString = "";

# Check to see if the arguments are empty
if (not defined $fileName) {
    die "Please provide the file name\n";
    # exit the program
    exit;
}

if (not defined $wordToSearchFor) {
    die "Please provide the word to search for\n";
    # exit the program
    exit;
}

$wordToSearchFor = lc($wordToSearchFor);

# output the file name and word to search for
# print "File Name: $fileName\n";
# print "Word to search for: $wordToSearchFor\n";

# Open the file
open(my $file, '<', $fileName) or die "Could not open file '$fileName' $!";
# Read the file line by line
while (my $line = <$file>) {
    # print $line;
    # go though the line letter by letter
    for (my $i = 0; $i < length($line); $i++) {
        # Check to see if the current character is a white space
        if (substr($line, $i, 1) eq " ") {
            # If it is a white space, skip to the next character
            next;
        }
        # Check to see if the current character not a letter
        if (substr($line, $i, 1) !~ /[a-zA-Z]/) {
            # If it is not a letter, skip to the next character
            next;
        }
        # Convert the current character to lower case
        my $currentCharacter = lc(substr($line, $i, 1));
        # Append the current character to the converted string
        $convertedString .= $currentCharacter;
    }
}

print "Converted String: $convertedString\n";

our $count = 0;

for (my $i = length($convertedString); $i >= 0; $i--) {
    if (substr($convertedString, $i, 1) eq substr($wordToSearchFor, 0, 1) and substr($convertedString, $i - 1, 1) eq substr($wordToSearchFor, 1, 1))
    {
        $count++;
    }
}

print "Number of times the word '$wordToSearchFor' was found: $count\n";
# Close the file
close($file);