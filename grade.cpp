#include "grade.h"
#include "median.h"
#include "Student_info.h"

#include <stdexcept>
#include <vector>

using std::vector;
using std::domain_error;

double grade(double midterm, double final, double median)
{
	return midterm*0.3+final*0.5+median*0.2;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end())
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			students.erase(iter);
		}
		else
			++iter;
	}

	return fail;
}
