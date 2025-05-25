#include <stdio.h>

typedef struct {
    char first_name[11];
    int test_scores[13];
    float average;
} Student;

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int main() {
    Student students[5];
    int test_score_sum_all_students = 0;
    float average_test_score_all_students = 0.0;
    int index_highest_avg = 0;

    for (int i=0; i<5; i++) {
        int student_test_score_sum = 0;
        scanf("%10s", students[i].first_name);

        if (is_lowercase(students[i].first_name[0])) {
            students[i].first_name[0] -= 32;
        }

        for (int c=1; students[i].first_name[c] != '\0'; c++) {
            if (is_uppercase(students[i].first_name[c])) {
                students[i].first_name[c] += 32;
            }
        }

        for (int j=0; j<13; j++) {
            scanf("%d", &students[i].test_scores[j]);
            student_test_score_sum += students[i].test_scores[j];
        }

        students[i].average = student_test_score_sum / 13.0;

        if (students[i].average > students[index_highest_avg].average) {
            index_highest_avg = i;
        }

        test_score_sum_all_students += student_test_score_sum;
    }

    average_test_score_all_students = test_score_sum_all_students / (5.0 * 13.0);

    // list the names
    printf("%s\n", students[index_highest_avg].first_name);
    for (int i=0; i<5; i++) {
        if (students[i].average < average_test_score_all_students) {
            printf("%s\n", students[i].first_name);
        }
    }

    return 0;
}