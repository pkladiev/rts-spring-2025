constexpr uint8_t INTERRUPT_PIN = 3;
constexpr size_t SAMPLE_SIZE = 100;
constexpr size_t SKIP_COUNT = 2;

volatile size_t interrupt_count = 0;
volatile size_t sample_count = 0;
volatile uint32_t sum_of_measurements = 0;
uint32_t measurements[SAMPLE_SIZE];
volatile uint32_t previous_time = 0;


void handleInterrupt() {
    uint32_t current_time = micros();
    uint32_t time_difference = current_time - previous_time;
    
    interrupt_count++;
    
    if (interrupt_count > SKIP_COUNT && sample_count < SAMPLE_SIZE) {
        measurements[sample_count] = time_difference;
        sum_of_measurements += time_difference;
        sample_count++;
    }
    
    previous_time = current_time;
}

void processMeasurements() {
    const float mean_interval = sum_of_measurements / static_cast<float>(SAMPLE_SIZE);
    float sum_of_squared_deviations = 0.0f;
    
    for (size_t i = 0; i < SAMPLE_SIZE; ++i) {
        float deviation = measurements[i] - mean_interval;
        sum_of_squared_deviations += deviation * deviation;
    }
    
    const float root_mean_square_deviation = sqrt(sum_of_squared_deviations / SAMPLE_SIZE);
    
    Serial.print("Mean: ");
    Serial.print(mean_interval);
    Serial.print(" us, RMS Deviation: ");
    Serial.print(root_mean_square_deviation);
    Serial.println(" us");
}

void setup() {
    Serial.begin(9600);
    pinMode(INTERRUPT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), handleInterrupt, HIGH);
}

void loop() {
    if (sample_count >= SAMPLE_SIZE) {
        noInterrupts();
        processMeasurements();
        sample_count = 0;
        interrupt_count = 0;
        sum_of_measurements = 0;
        interrupts();
    }
}
