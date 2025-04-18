#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <random>
#include <ctime>
#include <fstream>

class Student
{
    protected:
        std::string firstName;
        std::string lastName;

        double gpa;
        int age;
        int gradYear;
        int gradLevel;
        bool isGraduate;
    public:
        Student(std::string firstName, std::string lastName, double gpa, int age, int gradYear, int gradLevel, bool isGraduate)
            : firstName(firstName), lastName(lastName), gpa(gpa), age(age), gradYear(gradYear), gradLevel(gradLevel), isGraduate(isGraduate) {}
        ~Student() {}

        // Getters
        std::string getFirstName() { return firstName; }
        std::string getLastName() { return lastName; }
        std::string getFullName() { return firstName + " " + lastName; }
        double getGPA() { return gpa; }
        int getAge() { return age; }
        int getGradYear() { return gradYear; }
        int getGradLevel() { return gradLevel; }
        bool getIsGraduate() { return isGraduate; }
        // Setters
        void setFirstName(std::string firstName) { this->firstName = firstName; }
        void setLastName(std::string lastName) { this->lastName = lastName; }
        void setGPA(double gpa) { this->gpa = gpa; }
        void setAge(int age) { this->age = age; }
        void setGradYear(int gradYear) { this->gradYear = gradYear; }
        void setGradLevel(int gradLevel) { this->gradLevel = gradLevel; }
        void setIsGraduate(bool isGraduate) { this->isGraduate = isGraduate; }

};

class PhysicsStudent : public Student
{
    private:
        std::string researchTopic;
        std::string consentration;
    public:
        PhysicsStudent(std::string firstName, std::string lastName, double gpa, int age, int gradYear, int gradLevel, bool isGraduate, std::string researchTopic, std::string consentration)
            : Student(firstName, lastName, gpa, age, gradYear, gradLevel, isGraduate), researchTopic(researchTopic), consentration(consentration) {}
        ~PhysicsStudent() {}

        std::string getResearchTopic() { return researchTopic; }
        std::string getConcentration() { return consentration; }

        void setResearchTopic(std::string researchTopic) { this->researchTopic = researchTopic; }
        void setConcentration(std::string consentration) { this->consentration = consentration; }
};

class ArtStudent : public Student
{
    private:
        std::string artMedium;
        std::string artStyle;
        std::string artEnfisis;
    public:
        ArtStudent(std::string firstName, std::string lastName, double gpa, int age, int gradYear, int gradLevel, bool isGraduate, std::string artMedium, std::string artStyle, std::string artEnfisis)
            : Student(firstName, lastName, gpa, age, gradYear, gradLevel, isGraduate), artMedium(artMedium), artStyle(artStyle), artEnfisis(artEnfisis) {}
        ~ArtStudent() {}

        std::string getArtMedium() { return artMedium; }
        std::string getArtStyle() { return artStyle; }
        std::string getArtEnfisis() { return artEnfisis; }

        void setArtMedium(std::string artMedium) { this->artMedium = artMedium; }
        void setArtStyle(std::string artStyle) { this->artStyle = artStyle; }
        void setArtEnfisis(std::string artEnfisis) { this->artEnfisis = artEnfisis; }
};

// Function to generate a random GPA between 0.0 and 4.0
double generateRandomGPA()
{
    return static_cast<double>(rand()) / RAND_MAX * 4.0;
}

int main()
{
    std::vector<std::unique_ptr<PhysicsStudent>> physicsStudents;
    std::vector<std::unique_ptr<ArtStudent>> artStudents;

    // Add PhysicsStudent objects to the vector
    for (int i = 0; i < 5; ++i)
    {
        physicsStudents.push_back(std::make_unique<PhysicsStudent>(
            "", "", 0.0, 0, 0, 0, false, "", "")); // Default initialization
    }

    // Add ArtStudent objects to the vector
    for (int i = 0; i < 5; ++i)
    {
        artStudents.push_back(std::make_unique<ArtStudent>(
            "", "", 0.0, 0, 0, 0, false, "", "", "")); // Default initialization
    }

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));
    // Generate random students
    physicsStudents[0]->setFirstName("John");
    physicsStudents[0]->setLastName("Doe");
    physicsStudents[0]->setGPA(generateRandomGPA());
    physicsStudents[0]->setAge(rand() % 10 + 20);
    physicsStudents[0]->setGradYear(rand() % 10 + 2023);
    physicsStudents[0]->setGradLevel(rand() % 3 + 1);
    physicsStudents[0]->setIsGraduate(rand() % 2 == 0);
    physicsStudents[0]->setResearchTopic("Quantum Mechanics");
    physicsStudents[0]->setConcentration("Theoretical Physics");

    physicsStudents[1]->setFirstName("Jane");
    physicsStudents[1]->setLastName("Smith");
    physicsStudents[1]->setGPA(generateRandomGPA());
    physicsStudents[1]->setAge(rand() % 10 + 20);
    physicsStudents[1]->setGradYear(rand() % 10 + 2023);
    physicsStudents[1]->setGradLevel(rand() % 3 + 1);
    physicsStudents[1]->setIsGraduate(rand() % 2 == 0);
    physicsStudents[1]->setResearchTopic("Astrophysics");
    physicsStudents[1]->setConcentration("Cosmology");

    physicsStudents[2]->setFirstName("Alice");
    physicsStudents[2]->setLastName("Johnson");
    physicsStudents[2]->setGPA(generateRandomGPA());
    physicsStudents[2]->setAge(rand() % 10 + 20);
    physicsStudents[2]->setGradYear(rand() % 10 + 2023);
    physicsStudents[2]->setGradLevel(rand() % 3 + 1);
    physicsStudents[2]->setIsGraduate(rand() % 2 == 0);
    physicsStudents[2]->setResearchTopic("Particle Physics");
    physicsStudents[2]->setConcentration("Experimental Physics");

    physicsStudents[3]->setFirstName("Bob");
    physicsStudents[3]->setLastName("Brown");
    physicsStudents[3]->setGPA(generateRandomGPA());
    physicsStudents[3]->setAge(rand() % 10 + 20);
    physicsStudents[3]->setGradYear(rand() % 10 + 2023);
    physicsStudents[3]->setGradLevel(rand() % 3 + 1);
    physicsStudents[3]->setIsGraduate(rand() % 2 == 0);
    physicsStudents[3]->setResearchTopic("Condensed Matter Physics");
    physicsStudents[3]->setConcentration("Solid State Physics");

    physicsStudents[4]->setFirstName("Charlie");
    physicsStudents[4]->setLastName("Davis");
    physicsStudents[4]->setGPA(generateRandomGPA());
    physicsStudents[4]->setAge(rand() % 10 + 20);
    physicsStudents[4]->setGradYear(rand() % 10 + 2023);
    physicsStudents[4]->setGradLevel(rand() % 3 + 1);
    physicsStudents[4]->setIsGraduate(rand() % 2 == 0);
    physicsStudents[4]->setResearchTopic("Nuclear Physics");
    physicsStudents[4]->setConcentration("Nuclear Engineering");

    artStudents[0]->setFirstName("Emily");
    artStudents[0]->setLastName("Clark");
    artStudents[0]->setGPA(generateRandomGPA());
    artStudents[0]->setAge(rand() % 10 + 20);
    artStudents[0]->setGradYear(rand() % 10 + 2023);
    artStudents[0]->setGradLevel(rand() % 3 + 1);
    artStudents[0]->setIsGraduate(rand() % 2 == 0);
    artStudents[0]->setArtMedium("Oil Paint");
    artStudents[0]->setArtStyle("Impressionism");
    artStudents[0]->setArtEnfisis("Landscape Painting");

    artStudents[1]->setFirstName("David");
    artStudents[1]->setLastName("Wilson");
    artStudents[1]->setGPA(generateRandomGPA());
    artStudents[1]->setAge(rand() % 10 + 20);
    artStudents[1]->setGradYear(rand() % 10 + 2023);
    artStudents[1]->setGradLevel(rand() % 3 + 1);
    artStudents[1]->setIsGraduate(rand() % 2 == 0);
    artStudents[1]->setArtMedium("Watercolor");
    artStudents[1]->setArtStyle("Abstract");
    artStudents[1]->setArtEnfisis("Portrait Painting");

    artStudents[2]->setFirstName("Sophia");
    artStudents[2]->setLastName("Garcia");
    artStudents[2]->setGPA(generateRandomGPA());
    artStudents[2]->setAge(rand() % 10 + 20);
    artStudents[2]->setGradYear(rand() % 10 + 2023);
    artStudents[2]->setGradLevel(rand() % 3 + 1);
    artStudents[2]->setIsGraduate(rand() % 2 == 0);
    artStudents[2]->setArtMedium("Acrylic");
    artStudents[2]->setArtStyle("Cubism");
    artStudents[2]->setArtEnfisis("Still Life Painting");

    artStudents[3]->setFirstName("Michael");
    artStudents[3]->setLastName("Martinez");
    artStudents[3]->setGPA(generateRandomGPA());
    artStudents[3]->setAge(rand() % 10 + 20);
    artStudents[3]->setGradYear(rand() % 10 + 2023);
    artStudents[3]->setGradLevel(rand() % 3 + 1);
    artStudents[3]->setIsGraduate(rand() % 2 == 0);
    artStudents[3]->setArtMedium("Charcoal");
    artStudents[3]->setArtStyle("Realism");
    artStudents[3]->setArtEnfisis("Figure Drawing");

    artStudents[4]->setFirstName("Olivia");
    artStudents[4]->setLastName("Hernandez");
    artStudents[4]->setGPA(generateRandomGPA());
    artStudents[4]->setAge(rand() % 10 + 20);
    artStudents[4]->setGradYear(rand() % 10 + 2023);
    artStudents[4]->setGradLevel(rand() % 3 + 1);
    artStudents[4]->setIsGraduate(rand() % 2 == 0);
    artStudents[4]->setArtMedium("Digital");
    artStudents[4]->setArtStyle("Surrealism");
    artStudents[4]->setArtEnfisis("Concept Art");

    double averagePhysGPA = 0.0;
    double averageArtGPA = 0.0;
    double totalGPA = 0.0;

    // Calculate average GPA for Physics students
    for (size_t i = 0; i < physicsStudents.size(); ++i)
    {
        averagePhysGPA += physicsStudents[i]->getGPA();
    }
    averagePhysGPA /= physicsStudents.size();

    // Calculate average GPA for Art students
    for (size_t i = 0; i < artStudents.size(); ++i)
    {
        averageArtGPA += artStudents[i]->getGPA();
    }
    averageArtGPA /= artStudents.size();

    // Calculate total GPA
    totalGPA = (averagePhysGPA + averageArtGPA) / 2.0;

    // Open a file to save the data
    std::ofstream out("students_data.dat");
    if (!out)
    {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return 1;
    }

    // Write PhysicsStudent data to the file
    out << "============Physics Students:============\n";
    for (size_t i = 0; i < physicsStudents.size(); ++i)
    { 
        out << "Name: " << physicsStudents[i]->getFullName() << "\n";
        out << "GPA: " << physicsStudents[i]->getGPA() << "\n";
        out << "Age: " << physicsStudents[i]->getAge() << "\n";
        out << "Graduation Year: " << physicsStudents[i]->getGradYear() << "\n";
        out << "Graduation Level: " << physicsStudents[i]->getGradLevel() << "\n";
        out << "Is Graduate: " << (physicsStudents[i]->getIsGraduate() ? "Yes" : "No") << "\n";
        out << "Research Topic: " << physicsStudents[i]->getResearchTopic() << "\n";
        out << "Concentration: " << physicsStudents[i]->getConcentration() << "\n";
        out << "-----------------------------\n";
    }
    out << "=====================================\n";
    out << "Average GPA for Physics Students: " << averagePhysGPA << "\n";
    out << "=====================================\n";

    // Write ArtStudent data to the file
    out << "\n============Art Students:============\n";
    for (size_t i = 0; i < artStudents.size(); ++i)
    {
        out << "Name: " << artStudents[i]->getFullName() << "\n";
        out << "GPA: " << artStudents[i]->getGPA() << "\n";
        out << "Age: " << artStudents[i]->getAge() << "\n";
        out << "Graduation Year: " << artStudents[i]->getGradYear() << "\n";
        out << "Graduation Level: " << artStudents[i]->getGradLevel() << "\n";
        out << "Is Graduate: " << (artStudents[i]->getIsGraduate() ? "Yes" : "No") << "\n";
        out << "Art Medium: " << artStudents[i]->getArtMedium() << "\n";
        out << "Art Style: " << artStudents[i]->getArtStyle() << "\n";
        out << "Art Enfisis: " << artStudents[i]->getArtEnfisis() << "\n";
        out << "-----------------------------\n";
    }
    out << "=====================================\n";
    out << "Average GPA for Art Students: " << averageArtGPA << "\n";
    out << "=====================================\n";
    out << "Total GPA: " << totalGPA << "\n";
    out << "=====================================\n";

    out.close(); // Close the file

    std::cout << "Student data has been written to 'students_data.dat'." << std::endl;


    return 0;
}