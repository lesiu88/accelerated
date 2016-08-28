#include "grade.h"
#include "median.h"
#include "Student_info.h"

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using	std::cin;
using	std::cout;
using	std::endl;

using	std::setprecision;
using	std::string;
using	std::streamsize;

using	std::vector;
using	std::istream;

using	std::domain_error;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record))
	{
		maxlen = std::max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i=0; i!=students.size(); ++i)
	{
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cin.precision();

			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e)
		{
			cout << e.what();
		}

		cout << endl;
	}
	return 0;
}
