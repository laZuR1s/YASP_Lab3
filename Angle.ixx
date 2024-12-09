module;


import <iostream>;
import <string>;

export module Angle;


export class Angle
{
private:
    int degrees{};
    unsigned int minutes{};
    std::string name;
    void normalize();
    int compare(const Angle& other) const;


public:
    Angle() : name("Ang") {}
    Angle(int degrees, unsigned int minutes, std::string name = "Ang");
    ~Angle();

    int get_degrees();
    int get_minutes();
    std::string get_name();
    void set_degrees(int degrees);
    void set_minutes(unsigned int minutes);
    void set_name(const std::string& name);

    void print(std::ostream& out = std::cout);
    void clear();
    void multiply(double number);
    void increase_by_minutes(unsigned int minutes);
    void decrease_by_minutes(unsigned int dminutes);
    std::string to_string();
    Angle plus(const Angle& other) const;

    Angle operator+(const Angle& other) const { return plus(other); }
    Angle operator*(double multiplier) const { Angle result = *this; result.multiply(multiplier); return result; }
    Angle operator/(double divisor) const { Angle result = *this; result.multiply(1 / divisor); return result; }
    Angle operator+(unsigned int additional_minutes) const { Angle result = *this; result.increase_by_minutes(additional_minutes); return result; }
    Angle operator-(unsigned int dec_minutes) const { Angle result = *this; result.decrease_by_minutes(dec_minutes); return result; }
    std::weak_ordering operator<=>(const Angle& other) const { return compare(other) <=> 0; }
    bool operator==(const Angle& other) const { return compare(other) == 0; }
    bool operator!=(const Angle& other) const { return compare(other) != 0; }

    friend std::istream& operator>>(std::istream& in, Angle& angle)
    {
        in >> angle.name;
        in >> angle.degrees;
        in.get();
        in >> angle.minutes;
        in.get();
        angle.normalize();
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Angle& angle)
    {
        out << angle.name << " " << angle.degrees << "* " << angle.minutes << '\'' << '\n';
        return out;
    }
};

void Angle::normalize()
{
    if (minutes >= 60) {
        if (degrees >= 0)
            degrees += minutes / 60;
        else
            degrees -= minutes / 60;
        minutes = minutes % 60;
    }

    if (degrees < 0 && minutes > 0) {
        --degrees;
        minutes = 60 - minutes;
    }

    degrees = degrees % 360;
    if (degrees < 0)
        degrees += 360;
}

Angle::Angle(int degrees, unsigned int minutes, std::string name)
    : degrees(degrees), minutes(minutes), name(name)
{
    normalize();
}

Angle::~Angle()
{
    clear();
}

int Angle::get_degrees() { return degrees; }
int Angle::get_minutes() { return minutes; }
std::string Angle::get_name() { return name; }

void Angle::set_degrees(int degrees)
{
    this->degrees = degrees;
    normalize();
}

void Angle::set_minutes(unsigned int minutes)
{
    this->minutes = minutes;
    normalize();
}

void Angle::set_name(const std::string& name)
{
    this->name = name;
}

void Angle::print(std::ostream& out)
{
    out << "Angle: " << name << ", Value: " << to_string();
}

void Angle::clear()
{
    degrees = 0;
    minutes = 0;
    name.clear();
}

std::string Angle::to_string()
{
    std::string result;

    unsigned int minutes_copy{ minutes };
    result += '\'';
    if (minutes_copy == 0)
        result += '0';
    else
    {
        while (minutes_copy > 0)
        {
            result += (minutes_copy % 10) + '0';
            minutes_copy /= 10;
        }
    }
    result += '*';

    int degrees_copy{ degrees };
    if (degrees_copy == 0)
        result += '0';
    else
    {
        while (degrees_copy > 0)
        {
            result += (degrees_copy % 10) + '0';
            degrees_copy /= 10;
        }
    }
    result = name + " " + result;
    return result;
}

void Angle::multiply(double number)
{
    double total_minutes = (degrees * 60 + static_cast<double>(minutes));
    total_minutes *= number;
    degrees = static_cast<int>(total_minutes / 60.0);
    minutes = static_cast<unsigned int>(fabs(total_minutes - degrees * 60));
    normalize();
}




void Angle::increase_by_minutes(unsigned int minutes)
{
    this->minutes += minutes;
    normalize();
}

void Angle::decrease_by_minutes(unsigned int dec_minutes)
{
    int max_minutes = 21600;
    unsigned int total_minutes = degrees * 60 + minutes;

    if (dec_minutes > total_minutes)
        total_minutes = max_minutes - (dec_minutes - total_minutes);
    else
        total_minutes -= dec_minutes;

    degrees = total_minutes / 60;
    minutes = total_minutes % 60;
    normalize();
}

int Angle::compare(const Angle& other) const
{
    int result{ 1 };
    if (degrees < other.degrees)
        result = -1;
    else if (degrees == other.degrees)
    {
        if (minutes == other.minutes)
            result = 0;
        else if (minutes < other.minutes)
            result = -1;
    }
    return result;
}

Angle Angle::plus(const Angle& other) const
{
    unsigned int total_minutes = minutes + other.minutes + static_cast<unsigned int>(degrees * 60) + static_cast<unsigned int>(other.degrees * 60);
    return Angle(0, total_minutes, name + "+" + other.name);
}
