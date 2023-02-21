// Test Display using a single 8-segment LED module
const int SegAPin = 22;  // Output pin associated with the "A" (top) segment
const int SegBPin = 23;  // Output pin associated with the "B" (top right) segment
const int SegCPin = 24;  // Output pin associated with the "C" (bottom right) segment
const int SegDPin = 25;  // Output pin associated with the "D" (bottom) segment
const int SegEPin = 26;  // Output pin associated with the "E" (bottom left) segment
const int SegFPin = 27;  // Output pin associated with the "F" (top left) segment
const int SegGPin = 28;  // Output pin associated with the "G" (middle) segment
const int SegDPPin = 29; // Output pin associated with the "DP" (decimal point)

// Called once at start up
void setup()
{
  // Initialize the led GPIO pins for output.
  pinMode(SegAPin, OUTPUT);
  pinMode(SegBPin, OUTPUT);
  pinMode(SegCPin, OUTPUT);
  pinMode(SegDPin, OUTPUT);
  pinMode(SegEPin, OUTPUT);
  pinMode(SegFPin, OUTPUT);
  pinMode(SegGPin, OUTPUT);
  pinMode(SegDPPin, OUTPUT);
  
  // Flash each segment in sequence for a short period of time,
  // so we can see if the circuit wiring is correct.

  const int flashTime = 250; // LED flast time (in milliseconds)

  FlashEachSegment(flashTime);
}

// Called repeatedly until the reset button is pressed
void loop()
{
  // Digit display hold time (in milliseconds)
  const int holdTime = 1000; // 1000 milliseconds = 1 second

  displayZero(holdTime);
  displayOne(holdTime);
  displayTwo(holdTime);
  displayThree(holdTime);
  displayFour(holdTime);
  displayFive(holdTime);
  displaySix(holdTime);
  displaySeven(holdTime);
  displayEight(holdTime);
  displayNine(holdTime);
}

// Display the digit "0"
void displayZero(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  holdPattern(holdTime);
}

// Display the digit "1"
void displayOne(int holdTime)
{
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  holdPattern(holdTime);
}

// Display the digit "2"
void displayTwo(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegGPin);  
  holdPattern(holdTime);
}

// Display the digit "3"
void displayThree(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Display the digit "4"
void displayFour(int holdTime)
{
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Display the digit "5"
void displayFive(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Display the digit "6"
void displaySix(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Display the digit "7"
void displaySeven(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  holdPattern(holdTime);
}

// Display the digit "8"
void displayEight(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Display the digit "9"
void displayNine(int holdTime)
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  holdPattern(holdTime);
}

// Implement a delay in milliseconds that also turns off
// all the segments to be ready for the next digit
void holdPattern(int holdTime)
{
  delay(holdTime);
  allSegmentsOff();
  delay(holdTime);
}

// Turn all of the segments to off
void allSegmentsOff(void)
{
  SegmentOff(SegAPin);
  SegmentOff(SegBPin);
  SegmentOff(SegCPin);
  SegmentOff(SegDPin);
  SegmentOff(SegDPin);
  SegmentOff(SegEPin);
  SegmentOff(SegFPin);
  SegmentOff(SegGPin);
}

// Flash each segment with a delay between segments.
void FlashEachSegment(int waitInMilliseconds)
{
  FlashSegment(SegAPin, waitInMilliseconds);
  FlashSegment(SegBPin, waitInMilliseconds);
  FlashSegment(SegCPin, waitInMilliseconds);
  FlashSegment(SegDPin, waitInMilliseconds);
  FlashSegment(SegEPin, waitInMilliseconds);
  FlashSegment(SegFPin, waitInMilliseconds);
  FlashSegment(SegGPin, waitInMilliseconds);
  FlashSegment(SegDPPin, waitInMilliseconds);
}

// Flash a segment for the specified on/off time.
void FlashSegment(int segPin, int waitInMilliseconds)
{
  SegmentOn(segPin);
  delay(waitInMilliseconds);
  SegmentOff(segPin);
  delay(waitInMilliseconds);
}

// Turn a segment on.
void SegmentOn(int segPin)
{
  digitalWrite(segPin, HIGH); //Common cathode: HIGH; Common Anode: LOW
}

// Turn a segment off.
void SegmentOff(int segPin)
{
  digitalWrite(segPin, LOW); //Common cathode: LOW; Common Anode: HIGH
}