#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
struct hr_suggestions {
  char name[30];
  char email[50];
  char hrname[30];
  char firmname[50];
  char jobpos[3];
  int compsum;
  int dessum;
  int totalsum;
} hr_suggestions[100], temp;

struct ap_suggestions {
  char name[30];
  char email[50];
  char firm[50];
  int compsum;
  int dessum;
  int totalsum;
} ap_suggestions[100], temp1;

struct hr_comp {
  char firm[30];
  char name[20];
  char login[10];
  char row1[30];
  char row2[30];
  char row3[30];
  char row4[30];
  char row5[30];
  char row6[30];
  char row7[30];
  char row8[30];
  char row9[30];
  char row10[30];
  char row11[30];
  char row12[30];
  char row13[30];
  char row14[30];
  char row15[30];
  char row16[30];
  char row17[30];
  char row18[30];
  char row19[30];
  char row20[30];
  char row21[30];
  char row22[30];
  char row23[30];
  char row24[30];
  char row25[30];
  char row26[30];
  char row27[30];
  char row28[30];
  char row29[30];
  char row30[30];
  char row31[30];
  char row32[30];
  char row33[30];
  char row34[30];
  char row35[30];
  char row36[30];
  char row37[30];
  char row38[30];
  char row39[30];
  char row40[30];
  char row41[30];
  char row42[30];
  char row43[30];
  char row44[30];
  char row45[30];
} hr_comp[100];

struct hr_des {
  char firm[30];
  char name[20];
  char login[10];
  char row1[30];
  char row2[30];
  char row3[30];
  char row4[30];
  char row5[30];
  char row6[30];
  char row7[30];
  char row8[30];
  char row9[30];
  char row10[30];
  char row11[30];
  char row12[30];
  char row13[30];
  char row14[30];
  char row15[30];
  char row16[30];
  char row17[30];
  char row18[30];
  char row19[30];
  char row20[30];
  char row21[30];
  char row22[30];
  char row23[30];
  char row24[30];
  char row25[30];
  char row26[30];
  char row27[30];
  char row28[30];
  char row29[30];
  char row30[30];
  char row31[30];
  char row32[30];
  char row33[30];
  char row34[30];
  char row35[30];
  char row36[30];
  char row37[30];
  char row38[30];
  char row39[30];
  char row40[30];
  char row41[30];
  char row42[30];
  char row43[30];
  char row44[30];
  char row45[30];
} hr_des[100];

struct ap_comp {
  char firm[30];
  char name[20];
  char login[10];
  char row1[30];
  char row2[30];
  char row3[30];
  char row4[30];
  char row5[30];
  char row6[30];
  char row7[30];
  char row8[30];
  char row9[30];
  char row10[30];
  char row11[30];
  char row12[30];
  char row13[30];
  char row14[30];
  char row15[30];
  char row16[30];
  char row17[30];
  char row18[30];
  char row19[30];
  char row20[30];
  char row21[30];
  char row22[30];
  char row23[30];
  char row24[30];
  char row25[30];
  char row26[30];
  char row27[30];
  char row28[30];
  char row29[30];
  char row30[30];
  char row31[30];
  char row32[30];
  char row33[30];
  char row34[30];
  char row35[30];
  char row36[30];
  char row37[30];
  char row38[30];
  char row39[30];
  char row40[30];
  char row41[30];
  char row42[30];
  char row43[30];
  char row44[30];
  char row45[30];
} ap_comp[100];

struct ap_des {
  char firm[30];
  char name[20];
  char login[10];
  char row1[30];
  char row2[30];
  char row3[30];
  char row4[30];
  char row5[30];
  char row6[30];
  char row7[30];
  char row8[30];
  char row9[30];
  char row10[30];
  char row11[30];
  char row12[30];
  char row13[30];
  char row14[30];
  char row15[30];
  char row16[30];
  char row17[30];
  char row18[30];
  char row19[30];
  char row20[30];
  char row21[30];
  char row22[30];
  char row23[30];
  char row24[30];
  char row25[30];
  char row26[30];
  char row27[30];
  char row28[30];
  char row29[30];
  char row30[30];
  char row31[30];
  char row32[30];
  char row33[30];
  char row34[30];
  char row35[30];
  char row36[30];
  char row37[30];
  char row38[30];
  char row39[30];
  char row40[30];
  char row41[30];
  char row42[30];
  char row43[30];
  char row44[30];
  char row45[30];
} ap_des[100];

bool is_unique(char *login_id) {
  FILE *file = fopen("login1.csv", "r");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  char buffer[6];
  while (fgets(buffer, 6, file)) {
    if (strcmp(login_id, buffer) == 0) {
      fclose(file);
      return false;
    }
  }

  fclose(file);
  return true;
}

void generate_login_id(char *login_id) {
  // Generate a random 6-digit ID
  srand(time(NULL));
  int i;
  for (i = 0; i < 6; i++) {
    login_id[i] = '0' + rand() % 10;
  }
  login_id[i] = '\0';
}

int checkCredentials(char *loginID, char *password, char *role) {
  FILE *file = fopen("login1.csv", "r");
  if (file == NULL) {
    printf("Failed to open file!\n");
    return 0;
  }

  char line[100];
  while (fgets(line, sizeof(line), file)) {
    char *token;
    char *storedLoginID;
    char *storedPassword;
    char *storedRole;

    token = strtok(line, ",");
    storedLoginID = token;

    token = strtok(NULL, ",");
    storedPassword = token;

    token = strtok(NULL, ",");
    storedRole = token;

    storedRole[strcspn(storedRole, "\n")] = 0; // Remove newline character

    if (strcmp(storedLoginID, loginID) == 0 &&
        strcmp(storedPassword, password) == 0) {
      strcpy(role, storedRole); // Copy the role to the 'role' parameter
      fclose(file);
      return 1; // Credentials match
    }
  }

  fclose(file);
  return 0; // Credentials do not match
}

int main(void) {

  printf("Welcome to the JHM Hiring Web! We not only open the doors to "
         "opportunities but also to a lifelong career. \n \n");
  printf("To proceed, Enter 1 if you have a login ID.\nEnter 2 to create a "
         "new account: ");
  printf("\n");
  int start;
  scanf("%d", &start);
  // name10,j0b10,hr10 ,i10,matchcount....used for case 2 editing
  // templine10,sum,templine11[500],j10,k10,flag for case 3
  char role[3], name10[30], hr10[10], line10[256], job10[2], templine10[500],
      templine11[500];
  int matchCount1 = 0, matchCount2 = 0, matchCount3 = 0, i10 = 0, j10 = 0,
      flag = 1, k10 = 0;

  while (1) {
    if (start == 1) {
      printf("You already have an account!\n");
      char loginID[100], password[100];

      printf("Enter login ID: ");
      scanf("%s", loginID);
      printf("\n");

      printf("Enter password: ");
      scanf("%s", password);
      printf("\n");

      if (checkCredentials(loginID, password, role)) {
        printf("Login successful!\n");
        break;
      } else {
        printf("Invalid login credentials.\n");
        printf("Re-enter details.\n");
      }
    }

    else if (start == 2) {
      char name[4], email[50], password[20], cpassword[20], dob[10];
      int mobile;
      printf("Enter name of user:");
      scanf("%s", name);
      printf("\n");
      printf("Enter email-id of user:");
      scanf("%s", email);
      printf("\n");
      printf("Enter password to be set:");
      scanf("%s", password);
      printf("\n");
      printf("Confirm password:");
      scanf("%s", cpassword);
      printf("\n");
      while (1) {
        if (strcmp(cpassword, password) != 0) {
          printf("Re-enter detail.\n");
          printf("Confirm password:");
          scanf("%s", cpassword);
          printf("\n");
        } else {
          break;
        }
      }
      printf("Enter Date of Birth of user:");
      scanf("%s", dob);
      printf("\n");
      printf("Enter AP for applicant(or) HR for hiring manager:");
      scanf("%s", role);
      while (1) {
        if (strcmp(role, "AP") != 0 && strcmp(role, "HR") != 0) {
          printf("Re-enter detail.");
          printf("Enter AP for applicant(or) HR for hiring manager:");
          scanf("%s", role);
        } else {
          break;
        }
      }
      printf("\n");
      printf("Enter mobile number: ");
      scanf("%d", &mobile);
      printf("\n");
      /*while (1) {
        if (mobile>= 1000000000 || (mobile <= 9999999998)) {
          printf("Re-enter detail.");
          printf("Enter mobile number: ");
          scanf("%d", &mobile);
        } else {
          break;
        }
      }*/
      char login_id[6];
      generate_login_id(login_id);
      while (!is_unique(login_id)) {
        generate_login_id(login_id);
      }
      printf("Generated Login ID: %s\n", login_id);
      FILE *file =
          fopen("user_details.csv", "a"); // Open the file in append mode

      if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
      }

      fprintf(file, "%s,%s,%s,%s,%s,%d,%s\n", name, email, password, dob, role,
              mobile, login_id);
      fclose(file);
      FILE *file1 = fopen("login1.csv", "a"); // Open the file in append mode

      if (file1 == NULL) {
        printf("Error opening file.\n");
        return 1;
      }

      fprintf(file1, "%s,%s,%s\n", login_id, password, role);
      fclose(file1);
      printf("Login ID generated and stored successfully!\n ");
      break;
    }
  }

  char name1[30], name2[30], field[40];
  int login;
  FILE *file =
      fopen("hr_details_comp.csv", "a"); // Open the file in append mode
  FILE *file1 =
      fopen("hr_details_des.csv", "a"); // Open the file in append mode
  FILE *file2 =
      fopen("ap_details_comp.csv", "a"); // Open the file in append mode
  FILE *file3 = fopen("ap_details_des.csv", "a");
  if (strcmp(role, "HR\0") == 0) {
    while (1) {
      printf("Welcome HR MANAGER!");
      printf("\nThe following provisions are available for the hiring manager "
             "and his/her team:\n");
      printf("1. To enter a vacancy(with the job description and the "
             "required fields with points assigned)");
      printf("\n2. To edit details of the vacancy entered.");
      printf("\n3. To get top three candidates for entered job along with "
             "accepting or rejecting job profiles suggested.");
      printf(
          "\n4. View details about JOB PROFILES accepted by the HR Manager.");
      printf("\n5. Exit from system");
      printf("\nEnter an option from the above provided features.(1-5):");
      int choice1;
      scanf("%d", &choice1);

      // to enter details of the job vacancy
      if (choice1 == 1) {

        printf("\nEnter name of Firm, HR Manager:");
        scanf("%s,%s", name1, name2);
        printf("\nEnter login Id:");
        scanf("%d", &login);
        fprintf(file, "%s,%s,%d,", name1, name2, login);
        fprintf(file1, "%s,%s,%d,", name1, name2, login);

        printf("\nWe allow you to change the choice preference and marks "
               "allocated for the below mentioned data only to ensure data "
               "protection!\n");
        printf("\n\nAlso, to avoid stray users and data protection ,only "
               "compulsory data can be changed.Therefore only if any of these "
               "fields have been entered as compulsory field in prior , they "
               "can be edited.\n\n");
        printf("\n1.Job Position");
        printf("\n2.Educational Qualification");
        printf("\n3.Educational Institution");
        printf("\n4.Work Experience");
        printf("\n5.Aggregate score");
        printf("\n6.Salary range");
        printf("\n7.Number of working hours");
        printf("\n8.Transportation");
        printf("\n9.Shift");
        printf("\n10.Work from Home");
        printf("WARNING:ENTER DATA WITH CAUTION !INCORRECT ENTRY CAN LEAD TO "
               "MISMATCH OF DATA!.\n");

        printf("\n\nEnter the below details to open a JOB vacancy.");
        printf("\n1.Software Developer");
        printf("\n2.Doctor(General Physician)");
        printf("\n3.Lawyer");
        printf("\n4.Teacher");
        printf("\n5.Marketing Manager");
        printf("\n6.Accountant");
        printf("\n7.Buisness Analyst");
        printf("\n8.Customer service representative");
        printf("\n9.Actuary");
        printf("\n10.Web Developer");
        printf("\n11.Cashier");
        printf("\n12.Data Entry worker");
        printf("\n13.Management consultancy");
        printf("\n14.Sales Manager");
        printf("\n15.Artist");
        printf("\n16.Financial Manager");
        printf("\n17.Insurance Agent");
        printf("\n18.Robotics engineer");
        printf("\n19.Hardware engineer");
        printf("\n20.Social Media Manager");
        printf("\nChoose field of vacancy from the above mentioned "
               "options(1-20):");
        int fieldchoice;
        strcpy(field, "Job Position\0");
        scanf("%d", &fieldchoice);
        fprintf(file, "%s,%d,%f,", field, fieldchoice, 50.0);
        fprintf(file1, "%d,%d,%d,", 0, 0, 0);

        printf("The Qualifications required for the job are mentioned below:");
        printf("\n1. B.E/B.tech");
        printf("\n2. B.E/B.tech+ M.s/M.B.A");
        printf("\n3. M.B.B.S");
        printf("\n4. B.A LLB/JD");
        printf("\n5. CFA, FRM");
        printf("\n6. B.F.A");
        printf("\nChoose qualification required from the above mentioned "
               "options(1-6):");
        int qualification;
        scanf("%d", &qualification);

        printf("\n Is Educational Qualification a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int eduscore;
        scanf("%d", &eduscore);
        float point, marks;
        printf("\n\nHow many points is alloted this particular field (out of  "
               "10):");
        scanf("%f", &point);
        if (eduscore == 1) {
          strcpy(field, "Educational Qualification\0");
          fprintf(file, "%s,%d,%f,", field, eduscore, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        }

        else {
          strcpy(field, "Educational Qualification");
          fprintf(file1, "%s,%d,%f,", field, eduscore, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("The Educational Institution compulsorily required or "
               "optional are mentioned below:");
        printf("\n1. IIT(Bombay,Madras,Delhi,Kharagpur)");
        printf("\n2. NIT(Trichy,Warangal,Suratkal,Roorkee)");
        printf("\n3. BITS(Pilani,Goa)");
        printf("\n4. Regional Colleges(Top 10)");
        printf("\n5. IMU(Kolkata,Chennai,Mumbai)");
        printf("\n6. Others.");
        printf("\nChoose Educational Institution from the above mentioned "
               "options(1-6):");
        int eduinst;
        scanf("%d", &eduinst);
        printf("\n Is Educational Institution a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int eduinst_pref;
        scanf("%d", &eduinst_pref);
        printf("\n\nHow many points is alloted this particular field (out of  "
               "10):");
        scanf("%f", &point);
        if (eduinst_pref == 1) {
          strcpy(field, "Educational Institution\0");
          fprintf(file, "%s,%d,%f,", field, eduscore, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Educational Institution\0");
          fprintf(file1, "%s,%d,%f,", field, eduscore, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("The Work Experience required for the job are mentioned below:");
        printf("\n1. 0-1 years");
        printf("\n2. 2-5 years");
        printf("\n3. 5-10 years");
        printf("\n4. 10+ years");
        printf("\n5. No prior work experience required for the job.");
        printf("\nChoose  work experience required from the "
               "above mentioned options(1-5):");
        int work_exp;
        scanf("%d", &work_exp);

        printf("\n Is the Work Experience a compulsorily field   or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int exp_score;
        scanf("%d", &exp_score);
        printf("\n\nHow many points is alloted this particular field (out of  "
               "10):");
        scanf("%f", &point);
        if (exp_score == 1) {
          strcpy(field, "Work Experience\0");
          fprintf(file, "%s,%d,%f,", field, work_exp, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Work Experience\0");
          fprintf(file1, "%s,%d,%f,", field, work_exp, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("The Aggregate score of 10th and 12th marks required for the "
               "job are mentioned below:");
        printf("\n1. 95-100 percentage.");
        printf("\n2. 85-95 percentage.");
        printf("\n3. 70-85 percentage.");
        printf("\n4. 60-70 percentage.");
        printf("\n5. Less than 70 percentage.");
        printf("\nChoose Aggregate score required from the above mentioned "
               "options(1-5):");
        int score;
        scanf("%d", &score);

        printf("\n Is the Aggregate Score a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");

        int agg_score;
        scanf("%d", &agg_score);
        printf("\n\nHow many points is alloted this particular field (out of  "
               "10):");
        scanf("%f", &point);
        if (agg_score == 1) {
          strcpy(field, "Aggregate score\0");
          fprintf(file, "%s,%d,%f,", field, score, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Aggregate score\0");
          fprintf(file1, "%s,%d,%f,", field, score, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nSalary offered per annum inclusive of all the perks are "
               "mentioned below:");
        printf("\n1. Less than 12 Lakhs");
        printf("\n2. 12-25 Lakhs");
        printf("\n3. 25-35 Lakhs");
        printf("\n4. 35-45 Lakhs");
        printf("\n5. More than 45 Lakhs");
        printf("\nChoose salary range offered from the above mentioned "
               "options(1-5):");
        int salary;
        scanf("%d", &salary);
        printf("\n Is Salary offered a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int sala_scr;
        scanf("%d", &sala_scr);
        printf("\n\nHow many points is alloted this particular field (out of "
               "      10):");
        scanf("%f", &point);
        if (sala_scr == 1) {
          strcpy(field, "Salary range\0");
          fprintf(file, "%s,%d,%f,", field, salary, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Salary range\0");
          fprintf(file1, "%s,%d,%f,", field, salary, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nNumber of working hours are mentioned below:");
        printf("\n1. 8 hours( 5 days a week)");
        printf("\n2. 7 hours(5 days a week)");
        printf("\n3. 6 hours(7 days a week)");
        printf("\n4. 9 hours(6 days a week)");
        printf("\n5. More than 9 hours(6 days a week)");
        printf("\nChoose Number of working hours from the above mentioned "
               "options(1-5):");
        int work_hours;
        scanf("%d", &work_hours);
        printf("\n\nHow many points is alloted this particular field (out of "
               "10):");
        scanf("%f", &point);
        printf("\n Is Number of working hours a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int hours_score;

        scanf("%d", &hours_score);
        if (hours_score == 1) {
          strcpy(field, "Number of working hours\0");
          fprintf(file, "%s,%d,%f,", field, work_hours, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Number of working hours\0");
          fprintf(file1, "%s,%d,%f,", field, work_hours, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nTransportation services are mentioned below:");
        printf("\n1. Pick up and drop by company bus");
        printf("\n2. Only morning Pick up by company pool car");
        printf("\n3. Only evening drop by company pool car");
        printf("\n4. Only for inter-district office visits");
        printf("\n5. No transportation services provided");
        printf("\nChoose transportation services offered from the above "
               "mentioned options(1-5):");
        int transport;
        scanf("%d", &transport);
        printf("\n\nHow many points is alloted this particular field (out of "
               "           10):");
        scanf("%f", &point);
        printf("\n Is Transportation a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int trans_score;

        scanf("%d", &trans_score);

        if (trans_score == 1) {
          strcpy(field, "Transportation\0");
          fprintf(file, "%s,%d,%f,", field, transport, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Transportation\0");
          fprintf(file1, "%s,%d,%f,", field, transport, 2.5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nShift of the job are mentioned below:");
        printf("\n1. Day shift");
        printf("\n2. Night shift");
        printf("\n3. Day shift 3 days a week , night shift 2 days a week");
        printf("\n4. Night shift 3 days a week , day shift 2 days a week");
        printf("\n5. Flexi Hours( Entry time flexible for the employee)");
        printf("\nChoose shift of the job from the above mentioned "
               "options(1-5):");
        int shift;
        scanf("%d", &shift);
        printf("\n\nHow many points is alloted this particular field (out of "
               "           10):");
        scanf("%f", &point);
        printf("\n Is Shift of the job a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int shift_score;
        scanf("%d", &shift_score);
        if (shift_score == 1) {
          strcpy(field, "Shift\0");
          fprintf(file, "%s,%d,%f,", field, shift, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Shift\0");
          fprintf(file1, "%s,%d,%f,", field, shift, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nProvision of work from home:");
        printf("\n1. Provided");
        printf("\n2. Not provided");
        printf("\nChoose Provision of work from home from the above "
               "mentioned options(1-2):");
        int wfh;
        scanf("%d", &wfh);
        printf("\n\nHow many points is alloted this particular field (out of "
               "           10):");
        scanf("%f", &point);
        printf("\n Is Provision of work from home a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int wfh_score;
        scanf("%d", &wfh_score);
        if (wfh_score == 1) {
          strcpy(field, "Work from Home\0");
          fprintf(file, "%s,%d,%f,", field, wfh, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Work from Home\0");
          fprintf(file1, "%s,%d,%f,", field, wfh, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nEmployee Type");
        printf("\n1.Temporary");
        printf("\n2.Permanent");
        printf("\nChoose from the above 2 options(1-2):");
        int et;
        scanf("%d", &et);
        printf("\n\nHow many points is alloted this particular field (out "
               "of            10):");
        scanf("%f", &point);
        printf("\n Is Employee Type a compulsorily field or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int emp_type_scr;
        scanf("%d", &emp_type_scr);
        if (emp_type_scr == 1) {
          strcpy(field, "Employee Type\0");
          fprintf(file, "%s,%d,%f,", field, et, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Employee Type\0");
          fprintf(file1, "%s,%d,%f,", field, et, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nJob Location of the mentioned vacancy: ");
        printf("\n1.Chennai");
        printf("\n2.Delhi");
        printf("\n3.Mumbai");
        printf("\n4.Madurai");
        printf("\n5.Kolkata");
        printf("\n6.Hyderabad");
        printf("\n7.Bengaluru");
        printf("\n8.Surat");
        printf("\n9.Ahmedabad ");
        printf("\n10.Pune");
        printf("\n11.Remote first( NO Geo-location constraints)");
        printf("\nChoose Job Location of vacancy from the above mentioned "
               "options(1-11):");
        int job_loc;
        scanf("%d", &job_loc);
        printf("\n\nHow many points is alloted this particular field (out of "
               "           10):");
        scanf("%f", &point);
        printf("\n Is Job location a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int loc_score;
        scanf("%d", &loc_score);
        if (loc_score == 1) {
          strcpy(field, "Job Location\0");
          fprintf(file, "%s,%d,%f,", field, job_loc, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {

          strcpy(field, "Job Location\0");
          fprintf(file1, "%s,%d,%f,", field, job_loc, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nNumber of paid leaves per year:");
        printf("\n1. 10 days CL+ 7 days SL");
        printf("\n2. 8 days CL+ 5 days SL");
        printf("\n3. 5 days CL+ 3 days SL");
        printf("\n4. No paid leaves");
        printf("\nChoose Number of paid leaves per year from the above "
               "mentioned options(1-4):");
        int leave;
        scanf("%d", &leave);
        printf("\n\nHow many points is alloted this particular field (out of "
               "           10):");
        scanf("%f", &point);
        printf("\n Is Number of paid leaves per year a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int leave_score;
        scanf("%d", &wfh_score);
        if (wfh_score == 1) {
          strcpy(field, "Number of paid leaves\0");
          fprintf(file, "%s,%d,%f,", field, leave, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Number of paid leaves\0");
          fprintf(file1, "%s,%d,%f,", field, leave, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nStock options and incentives");
        printf("\n1.Provided");
        printf("\n2.Not Provided");
        printf("\nChoose from the above 2 options(1-2):");
        int stock;
        scanf("%d", &stock);
        printf("\n\nHow many points is alloted this particular field (out "
               "of            10):");
        scanf("%f", &point);
        printf("\n Is this field compulsorily or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int stock_scr;
        scanf("%d", &stock_scr);
        if (stock_scr == 1) {
          strcpy(field, "Stock options and incentives\0");
          fprintf(file, "%s,%d,%f,", field, stock, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Stock options and incentives\0");
          fprintf(file1, "%s,%d,%f,", field, stock, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nMedical Insurance for family");
        printf("\n1.Provided");
        printf("\n2.Not Provided");
        printf("\nChoose from the above 2 options(1-2):");
        int insurance;
        scanf("%d", &insurance);
        printf("\n\nHow many points is alloted this particular field (out "
               "of            10):");
        scanf("%f", &point);
        printf("\n Is this field compulsory field or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int insurance_scr;
        scanf("%d", &insurance_scr);
        if (stock_scr == 1) {
          strcpy(field, "Medical Insurance for family\0");
          fprintf(file, "%s,%d,%f", field, insurance, 5 * point);
          fprintf(file1, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Medical Insurance for family\0");
          fprintf(file1, "%s,%d,%f", field, insurance, 2.5 * point);
          fprintf(file, "%d,%d,%d,", 0, 0, 0);
        }
        fprintf(file, "\n");
        fprintf(file1, "\n");
        printf("\nDetails successfully entered!");
        fclose(file);
        fclose(file1);
      }

      else if (choice1 == 2) {
        FILE *file = fopen("hr_details_comp.csv", "r");
        struct hr_comp hr_comp[100];

        char line[200];
        int i = 0;

        while (fgets(line, sizeof(line), file)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(hr_comp[i].firm, field, sizeof(hr_comp[i].firm) - 1);
              hr_comp[i].firm[sizeof(hr_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(hr_comp[i].name, field, sizeof(hr_comp[i].name) - 1);
              hr_comp[i].name[sizeof(hr_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(hr_comp[i].login, field, sizeof(hr_comp[i].login) - 1);
              hr_comp[i].login[sizeof(hr_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(hr_comp[i].row1, field, sizeof(hr_comp[i].row1) - 1);
              hr_comp[i].row1[sizeof(hr_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(hr_comp[i].row2, field, sizeof(hr_comp[i].row2) - 1);
              hr_comp[i].row2[sizeof(hr_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(hr_comp[i].row3, field, sizeof(hr_comp[i].row3) - 1);
              hr_comp[i].row3[sizeof(hr_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(hr_comp[i].row4, field, sizeof(hr_comp[i].row4) - 1);
              hr_comp[i].row4[sizeof(hr_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(hr_comp[i].row5, field, sizeof(hr_comp[i].row5) - 1);
              hr_comp[i].row5[sizeof(hr_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(hr_comp[i].row6, field, sizeof(hr_comp[i].row6) - 1);
              hr_comp[i].row6[sizeof(hr_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(hr_comp[i].row7, field, sizeof(hr_comp[i].row7) - 1);
              hr_comp[i].row7[sizeof(hr_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(hr_comp[i].row8, field, sizeof(hr_comp[i].row8) - 1);
              hr_comp[i].row8[sizeof(hr_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(hr_comp[i].row9, field, sizeof(hr_comp[i].row9) - 1);
              hr_comp[i].row9[sizeof(hr_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(hr_comp[i].row10, field, sizeof(hr_comp[i].row10) - 1);
              hr_comp[i].row10[sizeof(hr_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(hr_comp[i].row11, field, sizeof(hr_comp[i].row11) - 1);
              hr_comp[i].row11[sizeof(hr_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(hr_comp[i].row12, field, sizeof(hr_comp[i].row12) - 1);
              hr_comp[i].row12[sizeof(hr_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(hr_comp[i].row13, field, sizeof(hr_comp[i].row13) - 1);
              hr_comp[i].row13[sizeof(hr_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(hr_comp[i].row14, field, sizeof(hr_comp[i].row14) - 1);
              hr_comp[i].row14[sizeof(hr_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(hr_comp[i].row15, field, sizeof(hr_comp[i].row15) - 1);
              hr_comp[i].row15[sizeof(hr_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(hr_comp[i].row16, field, sizeof(hr_comp[i].row16) - 1);
              hr_comp[i].row16[sizeof(hr_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(hr_comp[i].row17, field, sizeof(hr_comp[i].row17) - 1);
              hr_comp[i].row17[sizeof(hr_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(hr_comp[i].row18, field, sizeof(hr_comp[i].row18) - 1);
              hr_comp[i].row18[sizeof(hr_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(hr_comp[i].row19, field, sizeof(hr_comp[i].row19) - 1);
              hr_comp[i].row19[sizeof(hr_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(hr_comp[i].row20, field, sizeof(hr_comp[i].row20) - 1);
              hr_comp[i].row20[sizeof(hr_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(hr_comp[i].row21, field, sizeof(hr_comp[i].row21) - 1);
              hr_comp[i].row21[sizeof(hr_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(hr_comp[i].row22, field, sizeof(hr_comp[i].row22) - 1);
              hr_comp[i].row22[sizeof(hr_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(hr_comp[i].row23, field, sizeof(hr_comp[i].row23) - 1);
              hr_comp[i].row23[sizeof(hr_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(hr_comp[i].row24, field, sizeof(hr_comp[i].row24) - 1);
              hr_comp[i].row24[sizeof(hr_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(hr_comp[i].row25, field, sizeof(hr_comp[i].row25) - 1);
              hr_comp[i].row25[sizeof(hr_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(hr_comp[i].row26, field, sizeof(hr_comp[i].row26) - 1);
              hr_comp[i].row26[sizeof(hr_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(hr_comp[i].row27, field, sizeof(hr_comp[i].row27) - 1);
              hr_comp[i].row27[sizeof(hr_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(hr_comp[i].row28, field, sizeof(hr_comp[i].row28) - 1);
              hr_comp[i].row28[sizeof(hr_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(hr_comp[i].row29, field, sizeof(hr_comp[i].row29) - 1);
              hr_comp[i].row29[sizeof(hr_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(hr_comp[i].row30, field, sizeof(hr_comp[i].row30) - 1);
              hr_comp[i].row30[sizeof(hr_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(hr_comp[i].row31, field, sizeof(hr_comp[i].row31) - 1);
              hr_comp[i].row31[sizeof(hr_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(hr_comp[i].row32, field, sizeof(hr_comp[i].row32) - 1);
              hr_comp[i].row32[sizeof(hr_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(hr_comp[i].row33, field, sizeof(hr_comp[i].row33) - 1);
              hr_comp[i].row33[sizeof(hr_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(hr_comp[i].row34, field, sizeof(hr_comp[i].row34) - 1);
              hr_comp[i].row34[sizeof(hr_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(hr_comp[i].row35, field, sizeof(hr_comp[i].row35) - 1);
              hr_comp[i].row35[sizeof(hr_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(hr_comp[i].row36, field, sizeof(hr_comp[i].row36) - 1);
              hr_comp[i].row36[sizeof(hr_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(hr_comp[i].row37, field, sizeof(hr_comp[i].row37) - 1);
              hr_comp[i].row37[sizeof(hr_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(hr_comp[i].row38, field, sizeof(hr_comp[i].row38) - 1);
              hr_comp[i].row38[sizeof(hr_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(hr_comp[i].row39, field, sizeof(hr_comp[i].row39) - 1);
              hr_comp[i].row39[sizeof(hr_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(hr_comp[i].row40, field, sizeof(hr_comp[i].row40) - 1);
              hr_comp[i].row40[sizeof(hr_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(hr_comp[i].row41, field, sizeof(hr_comp[i].row41) - 1);
              hr_comp[i].row41[sizeof(hr_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(hr_comp[i].row42, field, sizeof(hr_comp[i].row42) - 1);
              hr_comp[i].row42[sizeof(hr_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(hr_comp[i].row43, field, sizeof(hr_comp[i].row43) - 1);
              hr_comp[i].row43[sizeof(hr_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(hr_comp[i].row44, field, sizeof(hr_comp[i].row44) - 1);
              printf("row 44:%s", hr_comp[i].row44);
              hr_comp[i].row44[sizeof(hr_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(hr_comp[i].row45, field, sizeof(hr_comp[i].row45) - 1);
              hr_comp[i].row45[sizeof(hr_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        fclose(file);
        printf("\nEnter name of firm:");
        scanf("%s", name10);
        printf("\nEnter name of HR Manager:");
        scanf("%s", hr10);
        printf("\nEnter Job Position number:");
        scanf("%s", job10);
        // sum for comp sum , sum1 for des sum
        int flag = 0, sum = 0, k = 0, sum1 = 0;
        for (int y = 0; y < i; y = y + 2) {
          // to find hr details from compulsory file;
          if (strcmp(hr_comp[y].firm, name10) == 0 &&
              strcmp(hr_comp[y].name, hr10) == 0 &&
              strcmp(hr_comp[y].row2, job10) == 0) {
            flag = 1;
            printf("\nWe allow you to change the choice preference and marks "
                   "allocated for the below mentioned data only to ensure data "
                   "protection!\n");
            printf("\n\nCaution: Modify compulsory fields only for data "
                   "protection; incorrect access may lead to data loss.\n\n");
            printf("\nWhich of the following fields do you want to change the "
                   "value of?");
            printf("\n1.Job Position");
            printf("\n2.Educational Qualification");
            printf("\n3.Educational Institution");
            printf("\n4.Work Experience");
            printf("\n5.Aggregate score");
            printf("\n6.Salary range");
            printf("\n7.Number of working hours");
            printf("\n8.Transportation");
            printf("\n9.Shift");
            printf("\n10.Work from Home");
            printf("\nChoose a field number(1-10):");
            int choice_field;
            scanf("%d", &choice_field);

            if (choice_field == 1) {
              printf("\n1.Software Developer");
              printf("\n2.Doctor(General Physician)");
              printf("\n3.Lawyer");
              printf("\n4.Teacher");
              printf("\n5.Marketing Manager");
              printf("\n6.Accountant");
              printf("\n7.Buisness Analyst");
              printf("\n8.Customer service representative");
              printf("\n9.Actuary");
              printf("\n10.Web Developer");
              printf("\n11.Cashier");
              printf("\n12.Data Entry worker");
              printf("\n13.Management consultancy");
              printf("\n14.Sales Manager");
              printf("\n15.Artist");
              printf("\n16.Financial Manager");
              printf("\n17.Insurance Agent");
              printf("\n18.Robotics engineer");
              printf("\n19.Hardware engineer");
              printf("\n20.Social Media Manager");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = (new_point) * (5);
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row2, pref);
              strcpy(hr_comp[y].row3, strpoint);
            }
            if (choice_field == 2) {
              printf("\n1. B.E/B.tech");
              printf("\n2. B.E/B.tech+ M.s/M.B.A");
              printf("\n3. M.B.B.S");
              printf("\n4. B.A LLB/JD");
              printf("\n5. CFA, FRM");
              printf("\n6. B.F.A");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row5, pref);
              strcpy(hr_comp[y].row6, strpoint);
            }
            if (choice_field == 3) {
              printf("\n1. IIT(Bombay,Madras,Delhi,Kharagpur)");
              printf("\n2. NIT(Trichy,Warangal,Suratkal,Roorkee)");
              printf("\n3. BITS(Pilani,Goa)");
              printf("\n4. Regional Colleges(Top 10)");
              printf("\n5. IMU(Kolkata,Chennai,Mumbai)");
              printf("\n6. Others.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row8, pref);
              strcpy(hr_comp[y].row9, strpoint);
            }
            if (choice_field == 4) {
              printf("\n1. 0-1 years");
              printf("\n2. 2-5 years");
              printf("\n3. 5-10 years");
              printf("\n4. 10+ years");
              printf("\n5. No prior work experience required for the job.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row11, pref);
              strcpy(hr_comp[y].row12, strpoint);
            }
            if (choice_field == 5) {
              printf("\n1. 95-100 percentage.");
              printf("\n2. 85-95 percentage.");
              printf("\n3. 70-85 percentage.");
              printf("\n4. 60-70 percentage.");
              printf("\n5. Less than 70 percentage.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row14, pref);
              strcpy(hr_comp[y].row15, strpoint);
            }
            if (choice_field == 6) {
              printf("\n1. Less than 12 Lakhs");
              printf("\n2. 12-25 Lakhs");
              printf("\n3. 25-35 Lakhs");
              printf("\n4. 35-45 Lakhs");
              printf("\n5. More than 45 Lakhs");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row17, pref);
              strcpy(hr_comp[y].row18, strpoint);
            }
            if (choice_field == 7) {
              printf("\n1. 8 hours( 5 days a week)");
              printf("\n2. 7 hours(5 days a week)");
              printf("\n3. 6 hours(7 days a week)");
              printf("\n4. 9 hours(6 days a week)");
              printf("\n5. More than 9 hours(6 days a week)");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row20, pref);
              strcpy(hr_comp[y].row21, strpoint);
            }
            if (choice_field == 8) {
              printf("\n1. Pick up and drop by company bus");
              printf("\n2. Only morning Pick up by company pool car");
              printf("\n3. Only evening drop by company pool car");
              printf("\n4. Only for inter-district office visits");
              printf("\n5. No transportation services provided");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row23, pref);
              strcpy(hr_comp[y].row22, strpoint);
            }
            if (choice_field == 9) {
              printf("\n1. Day shift");
              printf("\n2. Night shift");
              printf(
                  "\n3. Day shift 3 days a week , night shift 2 days a week");
              printf(
                  "\n4. Night shift 3 days a week , day shift 2 days a week");
              printf("\n5. Flexi Hours( Entry time flexible for the employee)");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row25, pref);
              strcpy(hr_comp[y].row26, strpoint);
            }
            if (choice_field == 10) {
              printf("\n1. Provided");
              printf("\n2. Not provided");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              printf("Enter points allocated out of 10:\n");
              int new_point;
              scanf("%d", &new_point);
              int point = new_point * 5;
              char strpoint[30];
              sprintf(strpoint, "%d", point);
              strcpy(hr_comp[y].row28, pref);
              strcpy(hr_comp[y].row29, strpoint);
            }
          }
        }
        if (flag == 1) {
          int counter = 0;
          file = fopen("hr_details_comp.csv", "w");
          for (int x3 = 0; x3 < i; x3 = x3 + 2) {
            fprintf(
                file,
                "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,"
                "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,0,0,0,0,0,0,0,"
                "0,0,0,0,0,0\n",
                hr_comp[x3].firm, hr_comp[x3].name, hr_comp[x3].login,
                hr_comp[x3].row1, hr_comp[x3].row2, hr_comp[x3].row3,
                hr_comp[x3].row4, hr_comp[x3].row5, hr_comp[x3].row6,
                hr_comp[x3].row7, hr_comp[x3].row8, hr_comp[x3].row9,
                hr_comp[x3].row10, hr_comp[x3].row11, hr_comp[x3].row12,
                hr_comp[x3].row13, hr_comp[x3].row14, hr_comp[x3].row15,
                hr_comp[x3].row16, hr_comp[x3].row17, hr_comp[x3].row18,
                hr_comp[x3].row19, hr_comp[x3].row20, hr_comp[x3].row21,
                hr_comp[x3].row22, hr_comp[x3].row23, hr_comp[x3].row24,
                hr_comp[x3].row25, hr_comp[x3].row26, hr_comp[x3].row27,
                hr_comp[x3].row28, hr_comp[x3].row29, hr_comp[x3].row30,
                hr_comp[x3].row31, hr_comp[x3].row32);
            counter++;
            if (counter == ((i / 2))) {
              fclose(file);
              printf("\n\nUpdation occured succesfully!\n\n");
              printf("\n\n---------------------------------------\n\n");
              break;
            }
          }
        }
        /*for(int x3=0;x3<i;x3=x3+2){
          fprintf(file,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",hr_comp[x3].firm,hr_comp[x3].name,hr_comp[x3].login,hr_comp[x3].row1,hr_comp[x3].row2,hr_comp[x3].row3,hr_comp[x3].row4,hr_comp[x3].row5,hr_comp[x3].row6,hr_comp[x3].row7,hr_comp[x3].row8,hr_comp[x3].row9,hr_comp[x3].row10,hr_comp[x3].row11,hr_comp[x3].row12,hr_comp[x3].row13,hr_comp[x3].row14,hr_comp[x3].row15,hr_comp[x3].row16,hr_comp[x3].row17,hr_comp[x3].row18,hr_comp[x3].row19,hr_comp[x3].row20,hr_comp[x3].row21,hr_comp[x3].row22,hr_comp[x3].row23,hr_comp[x3].row24,hr_comp[x3].row25,hr_comp[x3].row26,hr_comp[x3].row27,hr_comp[x3].row28,hr_comp[x3].row29,hr_comp[x3].row30,hr_comp[x3].row31,hr_comp[x3].row32,hr_comp[x3].row33,hr_comp[x3].row34,hr_comp[x3].row35,hr_comp[x3].row36,hr_comp[x3].row37,hr_comp[x3].row38,hr_comp[x3].row39,hr_comp[x3].row40,hr_comp[x3].row41,hr_comp[x3].row42,hr_comp[x3].row43,hr_comp[x3].row44,hr_comp[x3].row45);
printf("successfully updated values.");}*/

        if (flag == 0) {
          printf("\nSorry ,above mentioned details along with Job vacancy not "
                 "found.\n");
        }
      }

      else if (choice1 == 3) {
        FILE *file = fopen("hr_details_comp.csv", "r");
        FILE *file1 = fopen("hr_details_des.csv", "r");
        FILE *file2 = fopen("ap_details_comp.csv", "r");
        FILE *file3 = fopen("ap_details_des.csv", "r");
        struct hr_comp hr_comp[100];
        struct hr_des hr_des[100];
        struct ap_comp ap_comp[100];
        struct ap_des ap_des[100];
        struct hr_suggestions hr_suggestions[100];

        char line[200];
        int i = 0;

        while (fgets(line, sizeof(line), file)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(hr_comp[i].firm, field, sizeof(hr_comp[i].firm) - 1);
              hr_comp[i].firm[sizeof(hr_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(hr_comp[i].name, field, sizeof(hr_comp[i].name) - 1);
              hr_comp[i].name[sizeof(hr_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(hr_comp[i].login, field, sizeof(hr_comp[i].login) - 1);
              hr_comp[i].login[sizeof(hr_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(hr_comp[i].row1, field, sizeof(hr_comp[i].row1) - 1);
              hr_comp[i].row1[sizeof(hr_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(hr_comp[i].row2, field, sizeof(hr_comp[i].row2) - 1);
              hr_comp[i].row2[sizeof(hr_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(hr_comp[i].row3, field, sizeof(hr_comp[i].row3) - 1);
              hr_comp[i].row3[sizeof(hr_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(hr_comp[i].row4, field, sizeof(hr_comp[i].row4) - 1);
              hr_comp[i].row4[sizeof(hr_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(hr_comp[i].row5, field, sizeof(hr_comp[i].row5) - 1);
              hr_comp[i].row5[sizeof(hr_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(hr_comp[i].row6, field, sizeof(hr_comp[i].row6) - 1);
              hr_comp[i].row6[sizeof(hr_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(hr_comp[i].row7, field, sizeof(hr_comp[i].row7) - 1);
              hr_comp[i].row7[sizeof(hr_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(hr_comp[i].row8, field, sizeof(hr_comp[i].row8) - 1);
              hr_comp[i].row8[sizeof(hr_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(hr_comp[i].row9, field, sizeof(hr_comp[i].row9) - 1);
              hr_comp[i].row9[sizeof(hr_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(hr_comp[i].row10, field, sizeof(hr_comp[i].row10) - 1);
              hr_comp[i].row10[sizeof(hr_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(hr_comp[i].row11, field, sizeof(hr_comp[i].row11) - 1);
              hr_comp[i].row11[sizeof(hr_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(hr_comp[i].row12, field, sizeof(hr_comp[i].row12) - 1);
              hr_comp[i].row12[sizeof(hr_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(hr_comp[i].row13, field, sizeof(hr_comp[i].row13) - 1);
              hr_comp[i].row13[sizeof(hr_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(hr_comp[i].row14, field, sizeof(hr_comp[i].row14) - 1);
              hr_comp[i].row14[sizeof(hr_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(hr_comp[i].row15, field, sizeof(hr_comp[i].row15) - 1);
              hr_comp[i].row15[sizeof(hr_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(hr_comp[i].row16, field, sizeof(hr_comp[i].row16) - 1);
              hr_comp[i].row16[sizeof(hr_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(hr_comp[i].row17, field, sizeof(hr_comp[i].row17) - 1);
              hr_comp[i].row17[sizeof(hr_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(hr_comp[i].row18, field, sizeof(hr_comp[i].row18) - 1);
              hr_comp[i].row18[sizeof(hr_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(hr_comp[i].row19, field, sizeof(hr_comp[i].row19) - 1);
              hr_comp[i].row19[sizeof(hr_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(hr_comp[i].row20, field, sizeof(hr_comp[i].row20) - 1);
              hr_comp[i].row20[sizeof(hr_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(hr_comp[i].row21, field, sizeof(hr_comp[i].row21) - 1);
              hr_comp[i].row21[sizeof(hr_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(hr_comp[i].row22, field, sizeof(hr_comp[i].row22) - 1);
              hr_comp[i].row22[sizeof(hr_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(hr_comp[i].row23, field, sizeof(hr_comp[i].row23) - 1);
              hr_comp[i].row23[sizeof(hr_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(hr_comp[i].row24, field, sizeof(hr_comp[i].row24) - 1);
              hr_comp[i].row24[sizeof(hr_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(hr_comp[i].row25, field, sizeof(hr_comp[i].row25) - 1);
              hr_comp[i].row25[sizeof(hr_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(hr_comp[i].row26, field, sizeof(hr_comp[i].row26) - 1);
              hr_comp[i].row26[sizeof(hr_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(hr_comp[i].row27, field, sizeof(hr_comp[i].row27) - 1);
              hr_comp[i].row27[sizeof(hr_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(hr_comp[i].row28, field, sizeof(hr_comp[i].row28) - 1);
              hr_comp[i].row28[sizeof(hr_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(hr_comp[i].row29, field, sizeof(hr_comp[i].row29) - 1);
              hr_comp[i].row29[sizeof(hr_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(hr_comp[i].row30, field, sizeof(hr_comp[i].row30) - 1);
              hr_comp[i].row30[sizeof(hr_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(hr_comp[i].row31, field, sizeof(hr_comp[i].row31) - 1);
              hr_comp[i].row31[sizeof(hr_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(hr_comp[i].row32, field, sizeof(hr_comp[i].row32) - 1);
              hr_comp[i].row32[sizeof(hr_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(hr_comp[i].row33, field, sizeof(hr_comp[i].row33) - 1);
              hr_comp[i].row33[sizeof(hr_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(hr_comp[i].row34, field, sizeof(hr_comp[i].row34) - 1);
              hr_comp[i].row34[sizeof(hr_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(hr_comp[i].row35, field, sizeof(hr_comp[i].row35) - 1);
              hr_comp[i].row35[sizeof(hr_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(hr_comp[i].row36, field, sizeof(hr_comp[i].row36) - 1);
              hr_comp[i].row36[sizeof(hr_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(hr_comp[i].row37, field, sizeof(hr_comp[i].row37) - 1);
              hr_comp[i].row37[sizeof(hr_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(hr_comp[i].row38, field, sizeof(hr_comp[i].row38) - 1);
              hr_comp[i].row38[sizeof(hr_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(hr_comp[i].row39, field, sizeof(hr_comp[i].row39) - 1);
              hr_comp[i].row39[sizeof(hr_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(hr_comp[i].row40, field, sizeof(hr_comp[i].row40) - 1);
              hr_comp[i].row40[sizeof(hr_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(hr_comp[i].row41, field, sizeof(hr_comp[i].row41) - 1);
              hr_comp[i].row41[sizeof(hr_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(hr_comp[i].row42, field, sizeof(hr_comp[i].row42) - 1);
              hr_comp[i].row42[sizeof(hr_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(hr_comp[i].row43, field, sizeof(hr_comp[i].row43) - 1);
              hr_comp[i].row43[sizeof(hr_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(hr_comp[i].row44, field, sizeof(hr_comp[i].row44) - 1);
              hr_comp[i].row44[sizeof(hr_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(hr_comp[i].row45, field, sizeof(hr_comp[i].row45) - 1);
              hr_comp[i].row45[sizeof(hr_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file1)) {
          char *field = strtok(line, ",");
          int field_count = 0;

          while (field) {
            if (field_count == 0) {
              strncpy(hr_des[i].firm, field, sizeof(hr_des[i].firm) - 1);
              hr_des[i].firm[sizeof(hr_des[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(hr_des[i].name, field, sizeof(hr_des[i].name) - 1);
              hr_des[i].name[sizeof(hr_des[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(hr_des[i].login, field, sizeof(hr_des[i].login) - 1);
              hr_des[i].login[sizeof(hr_des[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(hr_des[i].row1, field, sizeof(hr_des[i].row1) - 1);
              hr_des[i].row1[sizeof(hr_des[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(hr_des[i].row2, field, sizeof(hr_des[i].row2) - 1);
              hr_des[i].row2[sizeof(hr_des[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(hr_des[i].row3, field, sizeof(hr_des[i].row3) - 1);
              hr_des[i].row3[sizeof(hr_des[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(hr_des[i].row4, field, sizeof(hr_des[i].row4) - 1);
              hr_des[i].row4[sizeof(hr_des[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(hr_des[i].row5, field, sizeof(hr_des[i].row5) - 1);
              hr_des[i].row5[sizeof(hr_des[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(hr_des[i].row6, field, sizeof(hr_des[i].row6) - 1);
              hr_des[i].row6[sizeof(hr_des[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(hr_des[i].row7, field, sizeof(hr_des[i].row7) - 1);
              hr_des[i].row7[sizeof(hr_des[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(hr_des[i].row8, field, sizeof(hr_des[i].row8) - 1);
              hr_des[i].row8[sizeof(hr_des[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(hr_des[i].row9, field, sizeof(hr_des[i].row9) - 1);
              hr_des[i].row9[sizeof(hr_des[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(hr_des[i].row10, field, sizeof(hr_des[i].row10) - 1);
              hr_des[i].row10[sizeof(hr_des[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(hr_des[i].row11, field, sizeof(hr_des[i].row11) - 1);
              hr_des[i].row11[sizeof(hr_des[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(hr_des[i].row12, field, sizeof(hr_des[i].row12) - 1);
              hr_des[i].row12[sizeof(hr_des[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(hr_des[i].row13, field, sizeof(hr_des[i].row13) - 1);
              hr_des[i].row13[sizeof(hr_des[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(hr_des[i].row14, field, sizeof(hr_des[i].row14) - 1);
              hr_des[i].row14[sizeof(hr_des[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(hr_des[i].row15, field, sizeof(hr_des[i].row15) - 1);
              hr_des[i].row15[sizeof(hr_des[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(hr_des[i].row16, field, sizeof(hr_des[i].row16) - 1);
              hr_des[i].row16[sizeof(hr_des[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(hr_des[i].row17, field, sizeof(hr_des[i].row17) - 1);
              hr_des[i].row17[sizeof(hr_des[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(hr_des[i].row18, field, sizeof(hr_des[i].row18) - 1);
              hr_des[i].row18[sizeof(hr_des[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(hr_des[i].row19, field, sizeof(hr_des[i].row19) - 1);
              hr_des[i].row19[sizeof(hr_des[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(hr_des[i].row20, field, sizeof(hr_des[i].row20) - 1);
              hr_des[i].row20[sizeof(hr_des[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(hr_des[i].row21, field, sizeof(hr_des[i].row21) - 1);
              hr_des[i].row21[sizeof(hr_des[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(hr_des[i].row22, field, sizeof(hr_des[i].row22) - 1);
              hr_des[i].row22[sizeof(hr_des[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(hr_des[i].row23, field, sizeof(hr_des[i].row23) - 1);
              hr_des[i].row23[sizeof(hr_des[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(hr_des[i].row24, field, sizeof(hr_des[i].row24) - 1);
              hr_des[i].row24[sizeof(hr_des[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(hr_des[i].row25, field, sizeof(hr_des[i].row25) - 1);
              hr_des[i].row25[sizeof(hr_des[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(hr_des[i].row26, field, sizeof(hr_des[i].row26) - 1);
              hr_des[i].row26[sizeof(hr_des[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(hr_des[i].row27, field, sizeof(hr_des[i].row27) - 1);
              hr_des[i].row27[sizeof(hr_des[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(hr_des[i].row28, field, sizeof(hr_des[i].row28) - 1);
              hr_des[i].row28[sizeof(hr_des[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(hr_des[i].row29, field, sizeof(hr_des[i].row29) - 1);
              hr_des[i].row29[sizeof(hr_des[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(hr_des[i].row30, field, sizeof(hr_des[i].row30) - 1);
              hr_des[i].row30[sizeof(hr_des[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(hr_des[i].row31, field, sizeof(hr_des[i].row31) - 1);
              hr_des[i].row31[sizeof(hr_des[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(hr_des[i].row32, field, sizeof(hr_des[i].row32) - 1);
              hr_des[i].row32[sizeof(hr_des[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(hr_des[i].row33, field, sizeof(hr_des[i].row33) - 1);
              hr_des[i].row33[sizeof(hr_des[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(hr_des[i].row34, field, sizeof(hr_des[i].row34) - 1);
              hr_des[i].row34[sizeof(hr_des[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(hr_des[i].row35, field, sizeof(hr_des[i].row35) - 1);
              hr_des[i].row35[sizeof(hr_des[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(hr_des[i].row36, field, sizeof(hr_des[i].row36) - 1);
              hr_des[i].row36[sizeof(hr_des[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(hr_des[i].row37, field, sizeof(hr_des[i].row37) - 1);
              hr_des[i].row37[sizeof(hr_des[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(hr_des[i].row38, field, sizeof(hr_des[i].row38) - 1);
              hr_des[i].row38[sizeof(hr_des[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(hr_des[i].row39, field, sizeof(hr_des[i].row39) - 1);
              hr_des[i].row39[sizeof(hr_des[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(hr_des[i].row40, field, sizeof(hr_des[i].row40) - 1);
              hr_des[i].row40[sizeof(hr_des[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(hr_des[i].row41, field, sizeof(hr_des[i].row41) - 1);
              hr_des[i].row41[sizeof(hr_des[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(hr_des[i].row42, field, sizeof(hr_des[i].row42) - 1);
              hr_des[i].row42[sizeof(hr_des[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(hr_des[i].row43, field, sizeof(hr_des[i].row43) - 1);
              hr_des[i].row43[sizeof(hr_des[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(hr_des[i].row44, field, sizeof(hr_des[i].row44) - 1);
              hr_des[i].row44[sizeof(hr_des[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(hr_des[i].row45, field, sizeof(hr_des[i].row45) - 1);
              hr_des[i].row45[sizeof(hr_des[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file2)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(ap_comp[i].firm, field, sizeof(ap_comp[i].firm) - 1);
              ap_comp[i].firm[sizeof(ap_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(ap_comp[i].name, field, sizeof(ap_comp[i].name) - 1);
              ap_comp[i].name[sizeof(ap_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(ap_comp[i].login, field, sizeof(ap_comp[i].login) - 1);
              ap_comp[i].login[sizeof(ap_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(ap_comp[i].row1, field, sizeof(ap_comp[i].row1) - 1);
              ap_comp[i].row1[sizeof(ap_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(ap_comp[i].row2, field, sizeof(ap_comp[i].row2) - 1);
              ap_comp[i].row2[sizeof(ap_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(ap_comp[i].row3, field, sizeof(ap_comp[i].row3) - 1);
              ap_comp[i].row3[sizeof(ap_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(ap_comp[i].row4, field, sizeof(ap_comp[i].row4) - 1);
              ap_comp[i].row4[sizeof(ap_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(ap_comp[i].row5, field, sizeof(ap_comp[i].row5) - 1);
              ap_comp[i].row5[sizeof(ap_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(ap_comp[i].row6, field, sizeof(ap_comp[i].row6) - 1);
              ap_comp[i].row6[sizeof(ap_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(ap_comp[i].row7, field, sizeof(ap_comp[i].row7) - 1);
              ap_comp[i].row7[sizeof(ap_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(ap_comp[i].row8, field, sizeof(ap_comp[i].row8) - 1);
              ap_comp[i].row8[sizeof(ap_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(ap_comp[i].row9, field, sizeof(ap_comp[i].row9) - 1);
              ap_comp[i].row9[sizeof(ap_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(ap_comp[i].row10, field, sizeof(ap_comp[i].row10) - 1);
              ap_comp[i].row10[sizeof(ap_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(ap_comp[i].row11, field, sizeof(ap_comp[i].row11) - 1);
              ap_comp[i].row11[sizeof(ap_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(ap_comp[i].row12, field, sizeof(ap_comp[i].row12) - 1);
              ap_comp[i].row12[sizeof(ap_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(ap_comp[i].row13, field, sizeof(ap_comp[i].row13) - 1);
              ap_comp[i].row13[sizeof(ap_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(ap_comp[i].row14, field, sizeof(ap_comp[i].row14) - 1);
              ap_comp[i].row14[sizeof(ap_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(ap_comp[i].row15, field, sizeof(ap_comp[i].row15) - 1);
              ap_comp[i].row15[sizeof(ap_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(ap_comp[i].row16, field, sizeof(ap_comp[i].row16) - 1);
              ap_comp[i].row16[sizeof(ap_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(ap_comp[i].row17, field, sizeof(ap_comp[i].row17) - 1);
              ap_comp[i].row17[sizeof(ap_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(ap_comp[i].row18, field, sizeof(ap_comp[i].row18) - 1);
              ap_comp[i].row18[sizeof(ap_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(ap_comp[i].row19, field, sizeof(ap_comp[i].row19) - 1);
              ap_comp[i].row19[sizeof(ap_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(ap_comp[i].row20, field, sizeof(ap_comp[i].row20) - 1);
              ap_comp[i].row20[sizeof(ap_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(ap_comp[i].row21, field, sizeof(ap_comp[i].row21) - 1);
              ap_comp[i].row21[sizeof(ap_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(ap_comp[i].row22, field, sizeof(ap_comp[i].row22) - 1);
              ap_comp[i].row22[sizeof(ap_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(ap_comp[i].row23, field, sizeof(ap_comp[i].row23) - 1);
              ap_comp[i].row23[sizeof(ap_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(ap_comp[i].row24, field, sizeof(ap_comp[i].row24) - 1);
              ap_comp[i].row24[sizeof(ap_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(ap_comp[i].row25, field, sizeof(ap_comp[i].row25) - 1);
              ap_comp[i].row25[sizeof(ap_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(ap_comp[i].row26, field, sizeof(ap_comp[i].row26) - 1);
              ap_comp[i].row26[sizeof(ap_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(ap_comp[i].row27, field, sizeof(ap_comp[i].row27) - 1);
              ap_comp[i].row27[sizeof(ap_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(ap_comp[i].row28, field, sizeof(ap_comp[i].row28) - 1);
              ap_comp[i].row28[sizeof(ap_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(ap_comp[i].row29, field, sizeof(ap_comp[i].row29) - 1);
              ap_comp[i].row29[sizeof(ap_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(ap_comp[i].row30, field, sizeof(ap_comp[i].row30) - 1);
              ap_comp[i].row30[sizeof(ap_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(ap_comp[i].row31, field, sizeof(ap_comp[i].row31) - 1);
              ap_comp[i].row31[sizeof(ap_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(ap_comp[i].row32, field, sizeof(ap_comp[i].row32) - 1);
              ap_comp[i].row32[sizeof(ap_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(ap_comp[i].row33, field, sizeof(ap_comp[i].row33) - 1);
              ap_comp[i].row33[sizeof(ap_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(ap_comp[i].row34, field, sizeof(ap_comp[i].row34) - 1);
              ap_comp[i].row34[sizeof(ap_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(ap_comp[i].row35, field, sizeof(ap_comp[i].row35) - 1);
              ap_comp[i].row35[sizeof(ap_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(ap_comp[i].row36, field, sizeof(ap_comp[i].row36) - 1);
              ap_comp[i].row36[sizeof(ap_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(ap_comp[i].row37, field, sizeof(ap_comp[i].row37) - 1);
              ap_comp[i].row37[sizeof(ap_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(ap_comp[i].row38, field, sizeof(ap_comp[i].row38) - 1);
              ap_comp[i].row38[sizeof(ap_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(ap_comp[i].row39, field, sizeof(ap_comp[i].row39) - 1);
              ap_comp[i].row39[sizeof(ap_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(ap_comp[i].row40, field, sizeof(ap_comp[i].row40) - 1);
              ap_comp[i].row40[sizeof(ap_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(ap_comp[i].row41, field, sizeof(ap_comp[i].row41) - 1);
              ap_comp[i].row41[sizeof(ap_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(ap_comp[i].row42, field, sizeof(ap_comp[i].row42) - 1);
              ap_comp[i].row42[sizeof(ap_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(ap_comp[i].row43, field, sizeof(ap_comp[i].row43) - 1);
              ap_comp[i].row43[sizeof(ap_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(ap_comp[i].row44, field, sizeof(ap_comp[i].row44) - 1);
              ap_comp[i].row44[sizeof(ap_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(ap_comp[i].row45, field, sizeof(ap_comp[i].row45) - 1);
              ap_comp[i].row45[sizeof(ap_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file3)) {
          char *field = strtok(line, ",");
          int field_count = 0;

          while (field) {
            if (field_count == 0) {
              strncpy(ap_des[i].firm, field, sizeof(ap_des[i].firm) - 1);
              ap_des[i].firm[sizeof(ap_des[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(ap_des[i].name, field, sizeof(ap_des[i].name) - 1);
              ap_des[i].name[sizeof(ap_des[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(ap_des[i].login, field, sizeof(ap_des[i].login) - 1);
              ap_des[i].login[sizeof(ap_des[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(ap_des[i].row1, field, sizeof(ap_des[i].row1) - 1);
              ap_des[i].row1[sizeof(ap_des[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(ap_des[i].row2, field, sizeof(ap_des[i].row2) - 1);
              ap_des[i].row2[sizeof(ap_des[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(ap_des[i].row3, field, sizeof(ap_des[i].row3) - 1);
              ap_des[i].row3[sizeof(ap_des[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(ap_des[i].row4, field, sizeof(ap_des[i].row4) - 1);
              ap_des[i].row4[sizeof(ap_des[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(ap_des[i].row5, field, sizeof(ap_des[i].row5) - 1);
              ap_des[i].row5[sizeof(ap_des[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(ap_des[i].row6, field, sizeof(ap_des[i].row6) - 1);
              ap_des[i].row6[sizeof(ap_des[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(ap_des[i].row7, field, sizeof(ap_des[i].row7) - 1);
              ap_des[i].row7[sizeof(ap_des[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(ap_des[i].row8, field, sizeof(ap_des[i].row8) - 1);
              ap_des[i].row8[sizeof(ap_des[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(ap_des[i].row9, field, sizeof(ap_des[i].row9) - 1);
              ap_des[i].row9[sizeof(ap_des[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(ap_des[i].row10, field, sizeof(ap_des[i].row10) - 1);
              ap_des[i].row10[sizeof(ap_des[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(ap_des[i].row11, field, sizeof(ap_des[i].row11) - 1);
              ap_des[i].row11[sizeof(ap_des[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(ap_des[i].row12, field, sizeof(ap_des[i].row12) - 1);
              ap_des[i].row12[sizeof(ap_des[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(ap_des[i].row13, field, sizeof(ap_des[i].row13) - 1);
              ap_des[i].row13[sizeof(ap_des[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(ap_des[i].row14, field, sizeof(ap_des[i].row14) - 1);
              ap_des[i].row14[sizeof(ap_des[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(ap_des[i].row15, field, sizeof(ap_des[i].row15) - 1);
              ap_des[i].row15[sizeof(ap_des[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(ap_des[i].row16, field, sizeof(ap_des[i].row16) - 1);
              ap_des[i].row16[sizeof(ap_des[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(ap_des[i].row17, field, sizeof(ap_des[i].row17) - 1);
              ap_des[i].row17[sizeof(ap_des[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(ap_des[i].row18, field, sizeof(ap_des[i].row18) - 1);
              ap_des[i].row18[sizeof(ap_des[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(ap_des[i].row19, field, sizeof(ap_des[i].row19) - 1);
              ap_des[i].row19[sizeof(ap_des[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(ap_des[i].row20, field, sizeof(ap_des[i].row20) - 1);
              ap_des[i].row20[sizeof(ap_des[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(ap_des[i].row21, field, sizeof(ap_des[i].row21) - 1);
              ap_des[i].row21[sizeof(ap_des[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(ap_des[i].row22, field, sizeof(ap_des[i].row22) - 1);
              ap_des[i].row22[sizeof(ap_des[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(ap_des[i].row23, field, sizeof(ap_des[i].row23) - 1);
              ap_des[i].row23[sizeof(ap_des[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(ap_des[i].row24, field, sizeof(ap_des[i].row24) - 1);
              ap_des[i].row24[sizeof(ap_des[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(ap_des[i].row25, field, sizeof(ap_des[i].row25) - 1);
              ap_des[i].row25[sizeof(ap_des[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(ap_des[i].row26, field, sizeof(ap_des[i].row26) - 1);
              ap_des[i].row26[sizeof(ap_des[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(ap_des[i].row27, field, sizeof(ap_des[i].row27) - 1);
              ap_des[i].row27[sizeof(ap_des[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(ap_des[i].row28, field, sizeof(ap_des[i].row28) - 1);
              ap_des[i].row28[sizeof(ap_des[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(ap_des[i].row29, field, sizeof(ap_des[i].row29) - 1);
              ap_des[i].row29[sizeof(ap_des[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(ap_des[i].row30, field, sizeof(ap_des[i].row30) - 1);
              ap_des[i].row30[sizeof(ap_des[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(ap_des[i].row31, field, sizeof(ap_des[i].row31) - 1);
              ap_des[i].row31[sizeof(ap_des[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(ap_des[i].row32, field, sizeof(ap_des[i].row32) - 1);
              ap_des[i].row32[sizeof(ap_des[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(ap_des[i].row33, field, sizeof(ap_des[i].row33) - 1);
              ap_des[i].row33[sizeof(ap_des[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(ap_des[i].row34, field, sizeof(ap_des[i].row34) - 1);
              ap_des[i].row34[sizeof(ap_des[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(ap_des[i].row35, field, sizeof(ap_des[i].row35) - 1);
              ap_des[i].row35[sizeof(ap_des[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(ap_des[i].row36, field, sizeof(ap_des[i].row36) - 1);
              ap_des[i].row36[sizeof(ap_des[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(ap_des[i].row37, field, sizeof(ap_des[i].row37) - 1);
              ap_des[i].row37[sizeof(ap_des[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(ap_des[i].row38, field, sizeof(ap_des[i].row38) - 1);
              ap_des[i].row38[sizeof(ap_des[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(ap_des[i].row39, field, sizeof(ap_des[i].row39) - 1);
              ap_des[i].row39[sizeof(ap_des[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(ap_des[i].row40, field, sizeof(ap_des[i].row40) - 1);
              ap_des[i].row40[sizeof(ap_des[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(ap_des[i].row41, field, sizeof(ap_des[i].row41) - 1);
              ap_des[i].row41[sizeof(ap_des[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(ap_des[i].row42, field, sizeof(ap_des[i].row42) - 1);
              ap_des[i].row42[sizeof(ap_des[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(ap_des[i].row43, field, sizeof(ap_des[i].row43) - 1);
              ap_des[i].row43[sizeof(ap_des[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(ap_des[i].row44, field, sizeof(ap_des[i].row44) - 1);
              ap_des[i].row44[sizeof(ap_des[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(ap_des[i].row45, field, sizeof(ap_des[i].row45) - 1);
              ap_des[i].row45[sizeof(ap_des[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }

        printf("\nEnter name of firm:");
        scanf("%s", name10);
        printf("\nEnter name of HR Manager:");
        scanf("%s", hr10);
        printf("\nEnter Job Position number:");
        scanf("%s", job10);
        // sum for comp sum , sum1 for des sum
        int flag = 0, sum = 0, k = 0, sum1 = 0;
        for (int y = 0; y < i; y = y + 2) {
          // to find hr details from compulsory file;
          if (strcmp(hr_comp[y].firm, name10) == 0 &&
              strcmp(hr_comp[y].name, hr10) == 0 &&
              strcmp(hr_comp[y].row2, job10) == 0) {
            flag = 1;
            // matching details of the compulsory file
            for (int y1 = 0; y1 < i; y1++) {
              sum = 0;
              sum1 = 0;
              if ((strcmp(hr_comp[y].row4, ap_comp[y1].row4) == 0) &&
                  (strcmp(hr_comp[y].row1, ap_comp[y1].row1) == 0) &&
                  (strcmp(hr_comp[y].row2, ap_comp[y1].row2) == 0) &&
                  (strcmp(hr_comp[y].row5, ap_comp[y1].row5) == 0) &&
                  (strcmp(hr_comp[y].row7, ap_comp[y1].row7) == 0) &&
                  (strcmp(hr_comp[y].row8, ap_comp[y1].row8) == 0) &&
                  (strcmp(hr_comp[y].row10, ap_comp[y1].row10) == 0) &&
                  (strcmp(hr_comp[y].row11, ap_comp[y1].row11) == 0) &&
                  (strcmp(hr_comp[y].row13, ap_comp[y1].row13) == 0) &&
                  (strcmp(hr_comp[y].row14, ap_comp[y1].row14) == 0) &&
                  (strcmp(hr_comp[y].row16, ap_comp[y1].row16) == 0) &&
                  (strcmp(hr_comp[y].row17, ap_comp[y1].row17) == 0) &&
                  (strcmp(hr_comp[y].row19, ap_comp[y1].row19) == 0) &&
                  (strcmp(hr_comp[y].row20, ap_comp[y1].row20) == 0) &&
                  (strcmp(hr_comp[y].row22, ap_comp[y1].row22) == 0) &&
                  (strcmp(hr_comp[y].row23, ap_comp[y1].row23) == 0) &&
                  (strcmp(hr_comp[y].row25, ap_comp[y1].row25) == 0) &&
                  (strcmp(hr_comp[y].row26, ap_comp[y1].row26) == 0) &&
                  (strcmp(hr_comp[y].row28, ap_comp[y1].row28) == 0) &&
                  (strcmp(hr_comp[y].row29, ap_comp[y1].row29) == 0) &&
                  (strcmp(hr_comp[y].row31, ap_comp[y1].row31) == 0) &&
                  (strcmp(hr_comp[y].row32, ap_comp[y1].row32) == 0)) {
                sum = atof(hr_comp[y].row3) + atof(hr_comp[y].row6) +
                      atof(hr_comp[y].row9) + atof(hr_comp[y].row12) +
                      atof(hr_comp[y].row15) + atof(hr_comp[y].row18) +
                      atof(hr_comp[y].row21) + atof(hr_comp[y].row24) +
                      atof(hr_comp[y].row27) + atof(hr_comp[y].row30);
                hr_suggestions[k].compsum = sum;
                strcpy(hr_suggestions[k].name, ap_comp[y1].name);
                char email[30];
                strcpy(email, ap_comp[y1].name);
                strcat(email, "@hotmail.com");
                strcpy(hr_suggestions[k].email, email);
                if ((strcmp(hr_des[y].row1, ap_des[y1].row1) == 0) &&
                    (strcmp(hr_des[y].row2, ap_des[y1].row2) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row3);
                }
                if ((strcmp(hr_des[y].row4, ap_des[y1].row4) == 0) &&
                    (strcmp(hr_des[y].row5, ap_des[y1].row5) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row6);
                }
                if ((strcmp(hr_des[y].row7, ap_des[y1].row7) == 0) &&
                    (strcmp(hr_des[y].row8, ap_des[y1].row8) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row9);
                }
                if ((strcmp(hr_des[y].row10, ap_des[y1].row10) == 0) &&
                    (strcmp(hr_des[y].row11, ap_des[y1].row11) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row12);
                }
                if ((strcmp(hr_des[y].row13, ap_des[y1].row13) == 0) &&
                    (strcmp(hr_des[y].row14, ap_des[y1].row14) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row15);
                }
                if ((strcmp(hr_des[y].row16, ap_des[y1].row16) == 0) &&
                    (strcmp(hr_des[y].row17, ap_des[y1].row17) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row18);
                }
                if ((strcmp(hr_des[y].row19, ap_des[y1].row19) == 0) &&
                    (strcmp(hr_des[y].row20, ap_des[y1].row20) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row21);
                }
                if ((strcmp(hr_des[y].row22, ap_des[y1].row22) == 0) &&
                    (strcmp(hr_des[y].row23, ap_des[y1].row23) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row24);
                }
                if ((strcmp(hr_des[y].row25, ap_des[y1].row25) == 0) &&
                    (strcmp(hr_des[y].row26, ap_des[y1].row26) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row27);
                }
                if ((strcmp(hr_des[y].row28, ap_des[y1].row28) == 0) &&
                    (strcmp(hr_des[y].row29, ap_des[y1].row29) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row30);
                }
                strcpy(hr_suggestions[k].hrname, hr_comp[y].name);
                strcpy(hr_suggestions[k].firmname, hr_comp[y].firm);
                strcpy(hr_suggestions[k].jobpos, hr_comp[y].row2);
                hr_suggestions[k].dessum = sum1;
                hr_suggestions[k].totalsum = sum1 + sum;
                k++;
              }
            }
          }
        }

        /*if((strcmp(hr_comp[y].row31,ap_comp[y].row31) == 0)
           &&(strcmp(hr_comp[y].row32, ap_comp[y].row32) == 0)
           &&(strcmp(hr_comp[y].row33, ap_comp[y].row33) == 0)
           &&(strcmp(hr_comp[y].row34, ap_comp[y].row34) == 0)
           &&(strcmp(hr_comp[y].row35, ap_comp[y].row35) == 0)
           &&(strcmp(hr_comp[y].row36, ap_comp[y].row36) == 0)
           &&(strcmp(hr_comp[y].row37, ap_comp[y].row37) == 0)
           &&(strcmp(hr_comp[y].row38, ap_comp[y].row38) == 0)
           &&(strcmp(hr_comp[y].row39, ap_comp[y].row39) == 0)
           &&(strcmp(hr_comp[y].row40, ap_comp[y].row40) == 0)
           &&(strcmp(hr_comp[y].row41, ap_comp[y].row41) == 0)
           &&(strcmp(hr_comp[y].row42, ap_comp[y].row42) == 0)
           &&(strcmp(hr_comp[y].row43, ap_comp[y].row43) == 0)
           &&(strcmp(hr_comp[y].row44, ap_comp[y].row44) == 0)
           &&(strcmp(hr_comp[y].row45, ap_comp[y].row45) == 0)){ printf("\nall
           fields matched matched");}
                  }
                */
        fclose(file);
        fclose(file1);
        fclose(file2);
        fclose(file3);
        if (flag == 0) {
          printf("\nSorry ,above mentioned details along with Job vacancy not "
                 "found.\n");
        }
        if (flag == 1) {
          for (int x1 = 1; x1 < k; x1++) {
            for (int x2 = 0; x2 < k - x1; x2++) {
              if (hr_suggestions[x2].totalsum >
                  hr_suggestions[x2 + 1].totalsum) {
                temp = hr_suggestions[x2];
                hr_suggestions[x2] = hr_suggestions[x2 + 1];
                hr_suggestions[x2 + 1] = temp;
              }
            }
          }
          printf(
              "\nTop three suitable candidates for the mentioned JOb Vacancy "
              "are as follows:");
          for (int x1 = 0; x1 < 3; x1++) {
            printf("\nRank %d.\tName:%s\tEmail:%s\t", x1 + 1,
                   hr_suggestions[x1].name, hr_suggestions[x1].email);
          }
          FILE *file4 = fopen("hr_ranks.csv", "a");
          fprintf(file4, "%s,%s,%s", name10, hr10, job10);
          printf("\nEnter number of profiles you would like to accept:");
          int accept;
          scanf("%d", &accept);
          for (int y4 = 0; y4 < accept; y4++) {
            printf(
                "\nEnter Rank number of the profile you would like to continue "
                "and initiate recruitment process with(Rank number 1,2..):");
            int rank;
            scanf("%d", &rank);
            if (rank == 1) {
              fprintf(file4, ",%s,%s", hr_suggestions[0].name,
                      hr_suggestions[0].email);
            }
            if (rank == 2) {
              fprintf(file4, ",%s,%s", hr_suggestions[1].name,
                      hr_suggestions[1].email);
            }

            if (rank == 3) {
              fprintf(file4, ",%s,%s", hr_suggestions[2].name,
                      hr_suggestions[2].email);
            }
          }
          fprintf(file4, "\n");
          printf("\nPreferences noted.\n");
          fclose(file4);
        }
      }

      else if (choice1 == 4) {
        FILE *file4 = fopen("hr_ranks.csv", "r");
        struct hr_suggestions hr_suggestions[3];
        char name11[40], hr11[40], job11[3];
        // flag3 to navigate if profile found
        int flag3 = 0;
        printf("\nEnter name of firm:");
        scanf("%s", name11);
        printf("\nEnter name of HR Manager:");
        scanf("%s", hr11);
        printf("\nEnter Job Position number:");
        scanf("%s", job11);
        char line[256];
        char *token;

        // Read each line from the file
        while (fgets(line, sizeof(line), file4)) {
          // Create a copy of the line for tokenization
          char line_copy[256];
          strcpy(line_copy, line);

          // Split the line into tokens
          token = strtok(line_copy, ",");

          // Check if the first three values match the desired values
          if (token != NULL && strcmp(token, name11) == 0) {
            token = strtok(NULL, ",");
            if (token != NULL && strcmp(token, hr11) == 0) {
              token = strtok(NULL, ",");
              if (token != NULL && strcmp(token, job11) == 0) {
                flag3 = 1;
                printf("\nDetails about the HR manager along with the JOB "
                       "position entered and profiles accpeted \n");

                // Print all details in the found row
                token = strtok(line, ",");
                while (token != NULL) {
                  printf("%s\n", token);
                  token = strtok(NULL, ",");
                }
                break; // Exit the loop after finding the row
              }
            }
          }
        }

        // Close the file
        fclose(file4);
        if (flag3 == 0) {
          printf("\nSorry matching not initiated!\n");
        }
      }

      else if (choice1 == 5) {
        printf(
            "\n\nThank you so much for visiting our portal. We hope that our "
            "portal opened new doors to exciting opportunities.Good "
            "luck:)\n\n");
        return 1;
      }
    }
  }

  else if (strcmp(role, "AP\0") == 0) {
    while (1) {
      printf("\n\nWelcome APPLICANT!");
      printf("\n\n---------------------------------------\n\n");
      printf("\nThe following provisions are available for the applicant:\n");
      printf("\n1. To enter JOB profile");
      printf("\n2. To edit details of the JOB PROFILE entered.");
      printf("\n3. To get top three job vacancies for entered job profile "
             "along with "
             "accepting or rejecting job vacancies suggested.");
      printf("\n4.View details about JOB PROFILES accepted by the HR Manager.");
      printf("\n5.Exit from the system");
      printf("\nEnter an option from the above provided features.(1-5):");
      printf("\n\n---------------------------------------\n\n");

      int choice2;
      scanf("%d", &choice2);
      // to enter details of the job profile
      if (choice2 == 1) {

        printf("\nEnter name of Applicant:");
        scanf("%s", name1);
        printf("\nEnter login Id:");
        scanf("%d", &login);
        fprintf(file2, "%d,%s,%d,", 0, name1, login);
        fprintf(file3, "%d,%s,%d,", 0, name1, login);
        printf("\nWe allow you to change the choice preference and marks "
               "allocated for the below mentioned data only to ensure data "
               "protection!\n");
        printf("\n\nAlso, to avoid stray users and data protection ,only "
               "compulsory data can be changed.Therefore only if any of these "
               "fields have been entered as compulsory field in prior , they "
               "can be edited.\n\n");
        printf("\n1.Job Position");
        printf("\n2.Educational Qualification");
        printf("\n3.Educational Institution");
        printf("\n4.Work Experience");
        printf("\n5.Aggregate score");
        printf("\n6.Salary range");
        printf("\n7.Number of working hours");
        printf("\n8.Transportation");
        printf("\n9.Shift");
        printf("\n10.Work from Home");
        printf("WARNING:ENTER DATA WITH CAUTION !INCORRECT ENTRY CAN LEAD TO "
               "MISMATCH OF DATA!.\n");
        printf("\nEnter the below details to open a JOB Profile.");
        printf("\n1.Software Developer");
        printf("\n2.Doctor(General Physician)");
        printf("\n3.Lawyer");
        printf("\n4.Teacher");
        printf("\n5.Marketing Manager");
        printf("\n6.Accountant");
        printf("\n7.Business Analyst");
        printf("\n8.Customer service representative");
        printf("\n9.Actuary");
        printf("\n10.Web Developer");
        printf("\n11.Cashier");
        printf("\n12.Data Entry worker");
        printf("\n13.Management consultancy");
        printf("\n14.Sales Manager");
        printf("\n15.Artist");
        printf("\n16.Financial Manager");
        printf("\n17.Insurance Agent");
        printf("\n18.Robotics engineer");
        printf("\n19.Hardware engineer");
        printf("\n20.Social Media Manager");
        printf("\nChoose career field from the above mentioned "
               "options(1-20):");
        int fieldchoice;
        strcpy(field, "Job Position\0");
        scanf("%d", &fieldchoice);
        fprintf(file2, "%s,%d,%d,", field, fieldchoice, 0);
        fprintf(file1, "%d,%d,%d,", 0, 0, 0);

        printf("The Qualifications of the applicant are mentioned below:");
        printf("\n1. B.E/B.tech");
        printf("\n2. B.E/B.tech+ M.s/M.B.A");
        printf("\n3. M.B.B.S");
        printf("\n4. B.A LLB/JD");
        printf("\n5. CFA, FRM");
        printf("\n6. B.F.A");
        printf("\nChoose qualification from the above mentioned options(1-6):");
        int qualification;
        scanf("%d", &qualification);

        printf("\n Is this field  compulsorily or "
               "optional? Enter 1 for compulosry or 0 for optional.");

        int eduscore;
        scanf("%d", &eduscore);
        if (eduscore == 1) {
          strcpy(field, "Educational Qualification\0");
          fprintf(file2, "%s,%d,%d,", field, eduscore, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        }

        else {
          strcpy(field, "Educational Qualification");
          fprintf(file3, "%s,%d,%d,", field, eduscore, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("The Educational Institution are mentioned below:");
        printf("\n1. IIT(Bombay,Madras,Delhi,Kharagpur)");
        printf("\n2. NIT(Trichy,Warangal,Suratkal,Roorkee)");
        printf("\n3. BITS(Pilani,Goa)");
        printf("\n4. Regional Colleges(Top 10)");
        printf("\n5. IMU(Kolkata,Chennai,Mumbai)");
        printf("\n6. Others.");
        printf("\nChoose Educational Institution from the above mentioned "
               "options(1-6):");
        int eduinst;
        scanf("%d", &eduinst);
        printf("\n Is this field compulsorily or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int eduinst_pref;
        scanf("%d", &eduinst_pref);
        if (eduinst_pref == 1) {
          strcpy(field, "Educational Institution\0");
          fprintf(file2, "%s,%d,%d,", field, eduscore, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Educational Institution\0");
          fprintf(file3, "%s,%d,%d,", field, eduscore, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("The Work Experience of the applicant are mentioned below:");
        printf("\n1. 0-1 years");
        printf("\n2. 2-5 years");
        printf("\n3. 5-10 years");
        printf("\n4. 10+ years");
        printf("\n5. No prior work experience required for the job.");
        printf("\nChoose  work experience from the "
               "above mentioned options(1-5):");
        int work_exp;
        scanf("%d", &work_exp);

        printf("\n Is the this field compulsorily or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int exp_score;
        scanf("%d", &exp_score);

        if (exp_score == 1) {
          strcpy(field, "Work Experience\0");
          fprintf(file2, "%s,%d,%d,", field, work_exp, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Work Experience\0");
          fprintf(file3, "%s,%d,%d,", field, work_exp, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf(
            "The Aggregate score of 10th and 12th marks are mentioned below:");
        printf("\n1. 95-100 percentage.");
        printf("\n2. 85-95 percentage.");
        printf("\n3. 70-85 percentage.");
        printf("\n4. 60-70 percentage.");
        printf("\n5. Less than 70 percentage.");
        printf("\nChoose Aggregate score from the above mentioned "
               "options(1-5):");
        int score;
        scanf("%d", &score);

        printf("\n Is this field compulsorily or "
               "optional? Enter 1 for compulosry or 0 for optional.");

        int agg_score;
        scanf("%d", &agg_score);

        if (agg_score == 1) {
          strcpy(field, "Aggregate score\0");
          fprintf(file2, "%s,%d,%d,", field, score, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Aggregate score\0");
          fprintf(file3, "%s,%d,%d,", field, score, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nSalary expected per annum inclusive of all the perks are "
               "mentioned below:");
        printf("\n1. Less than 12 Lakhs");
        printf("\n2. 12-25 Lakhs");
        printf("\n3. 25-35 Lakhs");
        printf("\n4. 35-45 Lakhs");
        printf("\n5. More than 45 Lakhs");
        printf("\nChoose salary range expected from the above mentioned "
               "options(1-5):");
        int salary;
        scanf("%d", &salary);
        printf("\n Is Salary offered a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int sala_scr;
        scanf("%d", &sala_scr);

        if (sala_scr == 1) {
          strcpy(field, "Salary range\0");
          fprintf(file2, "%s,%d,%d,", field, salary, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Salary range\0");
          fprintf(file3, "%s,%d,%d,", field, salary, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nNumber of working hours are mentioned below:");
        printf("\n1. 8 hours( 5 days a week)");
        printf("\n2. 7 hours(5 days a week)");
        printf("\n3. 6 hours(7 days a week)");
        printf("\n4. 9 hours(6 days a week)");
        printf("\n5. More than 9 hours(6 days a week)");
        printf("\nChoose Number of working hours preferred from the above "
               "mentioned "
               "options(1-5):");
        int work_hours;
        scanf("%d", &work_hours);

        printf("\n Is Number of working hours a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int hours_score;

        scanf("%d", &hours_score);
        if (hours_score == 1) {
          strcpy(field, "Number of working hours\0");
          fprintf(file2, "%s,%d,%d,", field, work_hours, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Number of working hours\0");
          fprintf(file3, "%s,%d,%d,", field, work_hours, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nTransportation services are mentioned below:");
        printf("\n1. Pick up and drop by company bus");
        printf("\n2. Only morning Pick up by company pool car");
        printf("\n3. Only evening drop by company pool car");
        printf("\n4. Only for inter-district office visits");
        printf("\n5. No transportation services provided");
        printf("\nChoose transportation services preferred from the above "
               "mentioned options(1-5):");
        int transport;
        scanf("%d", &transport);

        printf("\n Is Transportation a compulsorily field or "
               "optional? Enter 1 for compulosry or 0 for optional.");
        int trans_score;

        scanf("%d", &trans_score);

        if (trans_score == 1) {
          strcpy(field, "Transportation\0");
          fprintf(file2, "%s,%d,%d,", field, transport, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Transportation\0");
          fprintf(file3, "%s,%d,%d,", field, transport, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nShift of the job are mentioned below:");
        printf("\n1. Day shift");
        printf("\n2. Night shift");
        printf("\n3. Day shift 3 days a week , night shift 2 days a week");
        printf("\n4. Night shift 3 days a week , day shift 2 days a week");
        printf("\n5. Flexi Hours( Entry time flexible for the employee)");
        printf("\nChoose shift of the job preferred from the above mentioned "
               "options(1-5):");
        int shift;
        scanf("%d", &shift);

        printf("\n Is Shift of the job a compulsorily field or "
               "optional? Enter 1 for compulsory or 0 for optional.");
        int shift_score;
        scanf("%d", &shift_score);
        if (shift_score == 1) {
          strcpy(field, "Shift\0");
          fprintf(file2, "%s,%d,%d,", field, shift, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Shift\0");
          fprintf(file3, "%s,%d,%d,", field, shift, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nProvision of work from home:");
        printf("\n1.Required");
        printf("\n2.Not Required");
        printf("\nChoose Provision of work from home from the above "
               "mentioned options(1-2):");
        int wfh;
        scanf("%d", &wfh);

        printf("\n Is Provision of work from hom a compulsorily field or "
               "optional? Enter 1 for compulsory or 0 for optional.");
        int wfh_score;
        scanf("%d", &wfh_score);
        if (wfh_score == 1) {
          strcpy(field, "Work from Home\0");
          fprintf(file2, "%s,%d,%d,", field, wfh, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Work from Home\0");
          fprintf(file3, "%s,%d,%d,", field, wfh, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nPreferred Employment:");
        printf("\n1.Temporary");
        printf("\n2.Permanent");
        int et;
        printf("\nEnter your choice(1-2):");
        scanf("%d", &et);

        printf("\n Is Employee Type a compulsorily field or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int emp_type_scr;
        scanf("%d", &emp_type_scr);
        if (emp_type_scr == 1) {
          strcpy(field, "Employee Type\0");
          fprintf(file2, "%s,%d,%d,", field, et, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Employee Type\0");
          fprintf(file3, "%s,%d,%d,", field, et, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nJob Location preferred: ");
        printf("\n1.Chennai");
        printf("\n2.Delhi");
        printf("\n3.Mumbai");
        printf("\n4.Madurai");
        printf("\n5.Kolkata");
        printf("\n6.Hyderabad");
        printf("\n7.Bengaluru");
        printf("\n8.Surat");
        printf("\n9.Ahmedabad ");
        printf("\n10.Pune");
        printf("\n11.Remote first( NO Geo-location constraints)");
        printf("\nChoose Job Location preferred from the above mentioned "
               "options(1-11):");
        int job_loc;
        scanf("%d", &job_loc);

        printf("\n Is Job location a compulsory field or "
               "optional? Enter 1 for compulsory or 0 for optional.");
        int loc_score;
        scanf("%d", &loc_score);
        if (loc_score == 1) {
          strcpy(field, "Job Location\0");
          fprintf(file2, "%s,%d,%d", field, job_loc, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {

          strcpy(field, "Job Location\0");
          fprintf(file3, "%s,%d,%d,", field, job_loc, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nNumber of paid leaves preferred per year:");
        printf("\n1. 10 days CL+ 7 days SL");
        printf("\n2. 8 days CL+ 5 days SL");
        printf("\n3. 5 days CL+ 3 days SL");
        printf("\n4. No paid leaves");
        printf("\nChoose Number of paid leaves per year from the above "
               "mentioned options(1-4):");
        int leave;
        scanf("%d", &leave);

        printf("\n Is this field or "
               "optional? Enter 1 for compulsory or 0 for optional.");
        int leave_score;
        scanf("%d", &wfh_score);
        if (wfh_score == 1) {
          strcpy(field, "Number of paid leaves\0");
          fprintf(file2, "%s,%d,%d,", field, leave, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Number of paid leaves\0");
          fprintf(file3, "%s,%d,%d,", field, leave, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nStock options and incentives");
        printf("\n1.Required");
        printf("\n2.Not Required");
        int stock;
        printf("\nEnter your choice(1-2):");
        scanf("%d", &stock);

        printf("\n Is this field compulsorily or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int stock_scr;
        scanf("%d", &stock_scr);
        if (stock_scr == 1) {
          strcpy(field, "Stock options and incentives\0");
          fprintf(file2, "%s,%d,%d,", field, stock, 0);
          fprintf(file3, "%d,%d,%d,", 0, 0, 0);
        } else {
          strcpy(field, "Stock options and incentives\0");
          fprintf(file3, "%s,%d,%d,", field, stock, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nMedical Insurance for family");
        printf("\n1.Required");
        printf("\n2.Not Required");
        int insurance;
        printf("\nEnter your choice(1-2):");
        scanf("%d", &insurance);

        printf("\n Is this field compulsory or"
               "optional? Enter 1 for compulsory or 0 for optional");
        int insurance_scr;
        scanf("%d", &insurance_scr);
        if (stock_scr == 1) {
          strcpy(field, "Medical Insurance for family\0");
          fprintf(file2, "%s,%d,%d", field, insurance, 0);
          fprintf(file3, "%d,%d,%d", 0, 0, 0);
        } else {
          strcpy(field, "Medical Insurance for family\0");
          fprintf(file3, "%s,%d,%d", field, insurance, 0);
          fprintf(file2, "%d,%d,%d,", 0, 0, 0);
        }

        printf("\nEntered details and preferences successfully\n");
        fprintf(file2, "\n");
        fprintf(file3, "\n");
        fclose(file2);
        fclose(file3);
      }

      else if (choice2 == 2) {
        FILE *file2 = fopen("ap_details_comp.csv", "r");

        struct ap_comp ap_comp[100];

        char line[200];
        int i = 0;
        while (fgets(line, sizeof(line), file2)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(ap_comp[i].firm, field, sizeof(ap_comp[i].firm) - 1);
              ap_comp[i].firm[sizeof(ap_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(ap_comp[i].name, field, sizeof(ap_comp[i].name) - 1);
              ap_comp[i].name[sizeof(ap_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(ap_comp[i].login, field, sizeof(ap_comp[i].login) - 1);
              ap_comp[i].login[sizeof(ap_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(ap_comp[i].row1, field, sizeof(ap_comp[i].row1) - 1);
              ap_comp[i].row1[sizeof(ap_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(ap_comp[i].row2, field, sizeof(ap_comp[i].row2) - 1);
              ap_comp[i].row2[sizeof(ap_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(ap_comp[i].row3, field, sizeof(ap_comp[i].row3) - 1);
              ap_comp[i].row3[sizeof(ap_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(ap_comp[i].row4, field, sizeof(ap_comp[i].row4) - 1);
              ap_comp[i].row4[sizeof(ap_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(ap_comp[i].row5, field, sizeof(ap_comp[i].row5) - 1);
              ap_comp[i].row5[sizeof(ap_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(ap_comp[i].row6, field, sizeof(ap_comp[i].row6) - 1);
              ap_comp[i].row6[sizeof(ap_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(ap_comp[i].row7, field, sizeof(ap_comp[i].row7) - 1);
              ap_comp[i].row7[sizeof(ap_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(ap_comp[i].row8, field, sizeof(ap_comp[i].row8) - 1);
              ap_comp[i].row8[sizeof(ap_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(ap_comp[i].row9, field, sizeof(ap_comp[i].row9) - 1);
              ap_comp[i].row9[sizeof(ap_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(ap_comp[i].row10, field, sizeof(ap_comp[i].row10) - 1);
              ap_comp[i].row10[sizeof(ap_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(ap_comp[i].row11, field, sizeof(ap_comp[i].row11) - 1);
              ap_comp[i].row11[sizeof(ap_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(ap_comp[i].row12, field, sizeof(ap_comp[i].row12) - 1);
              ap_comp[i].row12[sizeof(ap_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(ap_comp[i].row13, field, sizeof(ap_comp[i].row13) - 1);
              ap_comp[i].row13[sizeof(ap_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(ap_comp[i].row14, field, sizeof(ap_comp[i].row14) - 1);
              ap_comp[i].row14[sizeof(ap_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(ap_comp[i].row15, field, sizeof(ap_comp[i].row15) - 1);
              ap_comp[i].row15[sizeof(ap_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(ap_comp[i].row16, field, sizeof(ap_comp[i].row16) - 1);
              ap_comp[i].row16[sizeof(ap_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(ap_comp[i].row17, field, sizeof(ap_comp[i].row17) - 1);
              ap_comp[i].row17[sizeof(ap_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(ap_comp[i].row18, field, sizeof(ap_comp[i].row18) - 1);
              ap_comp[i].row18[sizeof(ap_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(ap_comp[i].row19, field, sizeof(ap_comp[i].row19) - 1);
              ap_comp[i].row19[sizeof(ap_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(ap_comp[i].row20, field, sizeof(ap_comp[i].row20) - 1);
              ap_comp[i].row20[sizeof(ap_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(ap_comp[i].row21, field, sizeof(ap_comp[i].row21) - 1);
              ap_comp[i].row21[sizeof(ap_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(ap_comp[i].row22, field, sizeof(ap_comp[i].row22) - 1);
              ap_comp[i].row22[sizeof(ap_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(ap_comp[i].row23, field, sizeof(ap_comp[i].row23) - 1);
              ap_comp[i].row23[sizeof(ap_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(ap_comp[i].row24, field, sizeof(ap_comp[i].row24) - 1);
              ap_comp[i].row24[sizeof(ap_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(ap_comp[i].row25, field, sizeof(ap_comp[i].row25) - 1);
              ap_comp[i].row25[sizeof(ap_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(ap_comp[i].row26, field, sizeof(ap_comp[i].row26) - 1);
              ap_comp[i].row26[sizeof(ap_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(ap_comp[i].row27, field, sizeof(ap_comp[i].row27) - 1);
              ap_comp[i].row27[sizeof(ap_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(ap_comp[i].row28, field, sizeof(ap_comp[i].row28) - 1);
              ap_comp[i].row28[sizeof(ap_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(ap_comp[i].row29, field, sizeof(ap_comp[i].row29) - 1);
              ap_comp[i].row29[sizeof(ap_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(ap_comp[i].row30, field, sizeof(ap_comp[i].row30) - 1);
              ap_comp[i].row30[sizeof(ap_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(ap_comp[i].row31, field, sizeof(ap_comp[i].row31) - 1);
              ap_comp[i].row31[sizeof(ap_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(ap_comp[i].row32, field, sizeof(ap_comp[i].row32) - 1);
              ap_comp[i].row32[sizeof(ap_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(ap_comp[i].row33, field, sizeof(ap_comp[i].row33) - 1);
              ap_comp[i].row33[sizeof(ap_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(ap_comp[i].row34, field, sizeof(ap_comp[i].row34) - 1);
              ap_comp[i].row34[sizeof(ap_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(ap_comp[i].row35, field, sizeof(ap_comp[i].row35) - 1);
              ap_comp[i].row35[sizeof(ap_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(ap_comp[i].row36, field, sizeof(ap_comp[i].row36) - 1);
              ap_comp[i].row36[sizeof(ap_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(ap_comp[i].row37, field, sizeof(ap_comp[i].row37) - 1);
              ap_comp[i].row37[sizeof(ap_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(ap_comp[i].row38, field, sizeof(ap_comp[i].row38) - 1);
              ap_comp[i].row38[sizeof(ap_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(ap_comp[i].row39, field, sizeof(ap_comp[i].row39) - 1);
              ap_comp[i].row39[sizeof(ap_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(ap_comp[i].row40, field, sizeof(ap_comp[i].row40) - 1);
              ap_comp[i].row40[sizeof(ap_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(ap_comp[i].row41, field, sizeof(ap_comp[i].row41) - 1);
              ap_comp[i].row41[sizeof(ap_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(ap_comp[i].row42, field, sizeof(ap_comp[i].row42) - 1);
              ap_comp[i].row42[sizeof(ap_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(ap_comp[i].row43, field, sizeof(ap_comp[i].row43) - 1);
              ap_comp[i].row43[sizeof(ap_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(ap_comp[i].row44, field, sizeof(ap_comp[i].row44) - 1);
              ap_comp[i].row44[sizeof(ap_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(ap_comp[i].row45, field, sizeof(ap_comp[i].row45) - 1);
              ap_comp[i].row45[sizeof(ap_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        fclose(file2);
        char ap10[30], apjob10[30];
        printf("\nEnter name of Applicant:");
        scanf("%s", ap10);
        printf("\nEnter Job Position number:");
        scanf("%s", apjob10);
        // sum for comp sum , sum1 for des sum
        int flag = 0, sum = 0, k = 0, sum1 = 0;
        for (int y1 = 0; y1 < i; y1++) {
          // to find hr details from compulsory file;
          if ((strcmp(ap_comp[y1].name, ap10) == 0) &&
              (strcmp(ap_comp[y1].row2, apjob10) == 0)) {

            flag = 1;
            printf("\nWe allow you to change the choice preference and marks "
                   "allocated for the below mentioned data only to ensure data "
                   "protection!\n");
            printf("\n\nCaution: Modify compulsory fields only for data "
                   "protection; incorrect access may lead to data loss.\n\n");
            printf("\n\n---------------------------------------\n\n");
            printf("\nWhich of the following fields do you want to change the "
                   "value of?");
            printf("\n1.Job Position");
            printf("\n2.Educational Qualification");
            printf("\n3.Educational Institution");
            printf("\n4.Work Experience");
            printf("\n5.Aggregate score");
            printf("\n6.Salary range");
            printf("\n7.Number of working hours");
            printf("\n8.Transportation");
            printf("\n9.Shift");
            printf("\n10.Work from Home");
            printf("\nChoose a field number(1-10):");
            int choice_field;
            scanf("%d", &choice_field);
            printf("\n\n---------------------------------------\n\n");
            if (choice_field == 1) {
              printf("\n1.Software Developer");
              printf("\n2.Doctor(General Physician)");
              printf("\n3.Lawyer");
              printf("\n4.Teacher");
              printf("\n5.Marketing Manager");
              printf("\n6.Accountant");
              printf("\n7.Buisness Analyst");
              printf("\n8.Customer service representative");
              printf("\n9.Actuary");
              printf("\n10.Web Developer");
              printf("\n11.Cashier");
              printf("\n12.Data Entry worker");
              printf("\n13.Management consultancy");
              printf("\n14.Sales Manager");
              printf("\n15.Artist");
              printf("\n16.Financial Manager");
              printf("\n17.Insurance Agent");
              printf("\n18.Robotics engineer");
              printf("\n19.Hardware engineer");
              printf("\n20.Social Media Manager");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row2, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 2) {
              printf("\n1. B.E/B.tech");
              printf("\n2. B.E/B.tech+ M.s/M.B.A");
              printf("\n3. M.B.B.S");
              printf("\n4. B.A LLB/JD");
              printf("\n5. CFA, FRM");
              printf("\n6. B.F.A");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row5, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 3) {
              printf("\n1. IIT(Bombay,Madras,Delhi,Kharagpur)");
              printf("\n2. NIT(Trichy,Warangal,Suratkal,Roorkee)");
              printf("\n3. BITS(Pilani,Goa)");
              printf("\n4. Regional Colleges(Top 10)");
              printf("\n5. IMU(Kolkata,Chennai,Mumbai)");
              printf("\n6. Others.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row8, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 4) {
              printf("\n1. 0-1 years");
              printf("\n2. 2-5 years");
              printf("\n3. 5-10 years");
              printf("\n4. 10+ years");
              printf("\n5. No prior work experience required for the job.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row11, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 5) {
              printf("\n1. 95-100 percentage.");
              printf("\n2. 85-95 percentage.");
              printf("\n3. 70-85 percentage.");
              printf("\n4. 60-70 percentage.");
              printf("\n5. Less than 70 percentage.");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row14, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 6) {
              printf("\n1. Less than 12 Lakhs");
              printf("\n2. 12-25 Lakhs");
              printf("\n3. 25-35 Lakhs");
              printf("\n4. 35-45 Lakhs");
              printf("\n5. More than 45 Lakhs");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row17, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 7) {
              printf("\n1. 8 hours( 5 days a week)");
              printf("\n2. 7 hours(5 days a week)");
              printf("\n3. 6 hours(7 days a week)");
              printf("\n4. 9 hours(6 days a week)");
              printf("\n5. More than 9 hours(6 days a week)");
              printf("Enter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row20, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 8) {
              printf("\n1. Pick up and drop by company bus");
              printf("\n2. Only morning Pick up by company pool car");
              printf("\n3. Only evening drop by company pool car");
              printf("\n4. Only for inter-district office visits");
              printf("\n5. No transportation services provided");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row23, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 9) {
              printf("\n1. Day shift");
              printf("\n2. Night shift");
              printf(
                  "\n3. Day shift 3 days a week , night shift 2 days a week");
              printf(
                  "\n4. Night shift 3 days a week , day shift 2 days a week");
              printf("\n5. Flexi Hours( Entry time flexible for the employee)");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row25, pref);
              printf("\n\n---------------------------------------\n\n");
            }

            if (choice_field == 10) {
              printf("\n1. Provided");
              printf("\n2. Not provided");
              printf("\nEnter new preference number:\n");
              char pref[2];
              scanf("%s", pref);
              strcpy(ap_comp[y1].row27, pref);
              printf("\n\n---------------------------------------\n\n");
            }
          }
        }

        if (flag == 1) {
          int counter1 = 0;
          file2 = fopen("ap_details_comp.csv", "w");
          for (int x4 = 0; x4 < i; x4++) {
            fprintf(
                file2,
                "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,"
                "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,0,0,0,0,0,0,0,"
                "0,0,0,0,0,0\n",
                ap_comp[x4].firm, ap_comp[x4].name, ap_comp[x4].login,
                ap_comp[x4].row1, ap_comp[x4].row2, ap_comp[x4].row3,
                ap_comp[x4].row4, ap_comp[x4].row5, ap_comp[x4].row6,
                ap_comp[x4].row7, ap_comp[x4].row8, ap_comp[x4].row9,
                ap_comp[x4].row10, ap_comp[x4].row11, ap_comp[x4].row12,
                ap_comp[x4].row13, ap_comp[x4].row14, ap_comp[x4].row15,
                ap_comp[x4].row16, ap_comp[x4].row17, ap_comp[x4].row18,
                ap_comp[x4].row19, ap_comp[x4].row20, ap_comp[x4].row21,
                ap_comp[x4].row22, ap_comp[x4].row23, ap_comp[x4].row24,
                ap_comp[x4].row25, ap_comp[x4].row26, ap_comp[x4].row27,
                ap_comp[x4].row28, ap_comp[x4].row29, ap_comp[x4].row30,
                ap_comp[x4].row31, ap_comp[x4].row32);
            counter1++;
            if (counter1 == i - 1) {
              fclose(file2);
              printf("\n\nUpdation occured succesfully!\n\n");
              printf("\n\n---------------------------------------\n\n");
              break;
            }
          }
        }
        /*for(int x3=0;x3<i;x3=x3+2){
          fprintf(file,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",hr_comp[x3].firm,hr_comp[x3].name,hr_comp[x3].login,hr_comp[x3].row1,hr_comp[x3].row2,hr_comp[x3].row3,hr_comp[x3].row4,hr_comp[x3].row5,hr_comp[x3].row6,hr_comp[x3].row7,hr_comp[x3].row8,hr_comp[x3].row9,hr_comp[x3].row10,hr_comp[x3].row11,hr_comp[x3].row12,hr_comp[x3].row13,hr_comp[x3].row14,hr_comp[x3].row15,hr_comp[x3].row16,hr_comp[x3].row17,hr_comp[x3].row18,hr_comp[x3].row19,hr_comp[x3].row20,hr_comp[x3].row21,hr_comp[x3].row22,hr_comp[x3].row23,hr_comp[x3].row24,hr_comp[x3].row25,hr_comp[x3].row26,hr_comp[x3].row27,hr_comp[x3].row28,hr_comp[x3].row29,hr_comp[x3].row30,hr_comp[x3].row31,hr_comp[x3].row32,hr_comp[x3].row33,hr_comp[x3].row34,hr_comp[x3].row35,hr_comp[x3].row36,hr_comp[x3].row37,hr_comp[x3].row38,hr_comp[x3].row39,hr_comp[x3].row40,hr_comp[x3].row41,hr_comp[x3].row42,hr_comp[x3].row43,hr_comp[x3].row44,hr_comp[x3].row45);
printf("successfully updated values.");}*/

        if (flag == 0) {
          printf("\nSorry ,above mentioned details along with Job vacancy not "
                 "found.\n");
        }

      }

      else if (choice2 == 3) {
        FILE *file = fopen("hr_details_comp.csv", "r");
        FILE *file1 = fopen("hr_details_des.csv", "r");
        FILE *file2 = fopen("ap_details_comp.csv", "r");
        FILE *file3 = fopen("ap_details_des.csv", "r");
        struct hr_comp hr_comp[100];
        struct hr_des hr_des[100];
        struct ap_comp ap_comp[100];
        struct ap_des ap_des[100];
        struct ap_suggestions ap_suggestions[100];

        char line[200];
        int i = 0;

        while (fgets(line, sizeof(line), file)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(hr_comp[i].firm, field, sizeof(hr_comp[i].firm) - 1);
              hr_comp[i].firm[sizeof(hr_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(hr_comp[i].name, field, sizeof(hr_comp[i].name) - 1);
              hr_comp[i].name[sizeof(hr_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(hr_comp[i].login, field, sizeof(hr_comp[i].login) - 1);
              hr_comp[i].login[sizeof(hr_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(hr_comp[i].row1, field, sizeof(hr_comp[i].row1) - 1);
              hr_comp[i].row1[sizeof(hr_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(hr_comp[i].row2, field, sizeof(hr_comp[i].row2) - 1);
              hr_comp[i].row2[sizeof(hr_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(hr_comp[i].row3, field, sizeof(hr_comp[i].row3) - 1);
              hr_comp[i].row3[sizeof(hr_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(hr_comp[i].row4, field, sizeof(hr_comp[i].row4) - 1);
              hr_comp[i].row4[sizeof(hr_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(hr_comp[i].row5, field, sizeof(hr_comp[i].row5) - 1);
              hr_comp[i].row5[sizeof(hr_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(hr_comp[i].row6, field, sizeof(hr_comp[i].row6) - 1);
              hr_comp[i].row6[sizeof(hr_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(hr_comp[i].row7, field, sizeof(hr_comp[i].row7) - 1);
              hr_comp[i].row7[sizeof(hr_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(hr_comp[i].row8, field, sizeof(hr_comp[i].row8) - 1);
              hr_comp[i].row8[sizeof(hr_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(hr_comp[i].row9, field, sizeof(hr_comp[i].row9) - 1);
              hr_comp[i].row9[sizeof(hr_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(hr_comp[i].row10, field, sizeof(hr_comp[i].row10) - 1);
              hr_comp[i].row10[sizeof(hr_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(hr_comp[i].row11, field, sizeof(hr_comp[i].row11) - 1);
              hr_comp[i].row11[sizeof(hr_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(hr_comp[i].row12, field, sizeof(hr_comp[i].row12) - 1);
              hr_comp[i].row12[sizeof(hr_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(hr_comp[i].row13, field, sizeof(hr_comp[i].row13) - 1);
              hr_comp[i].row13[sizeof(hr_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(hr_comp[i].row14, field, sizeof(hr_comp[i].row14) - 1);
              hr_comp[i].row14[sizeof(hr_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(hr_comp[i].row15, field, sizeof(hr_comp[i].row15) - 1);
              hr_comp[i].row15[sizeof(hr_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(hr_comp[i].row16, field, sizeof(hr_comp[i].row16) - 1);
              hr_comp[i].row16[sizeof(hr_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(hr_comp[i].row17, field, sizeof(hr_comp[i].row17) - 1);
              hr_comp[i].row17[sizeof(hr_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(hr_comp[i].row18, field, sizeof(hr_comp[i].row18) - 1);
              hr_comp[i].row18[sizeof(hr_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(hr_comp[i].row19, field, sizeof(hr_comp[i].row19) - 1);
              hr_comp[i].row19[sizeof(hr_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(hr_comp[i].row20, field, sizeof(hr_comp[i].row20) - 1);
              hr_comp[i].row20[sizeof(hr_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(hr_comp[i].row21, field, sizeof(hr_comp[i].row21) - 1);
              hr_comp[i].row21[sizeof(hr_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(hr_comp[i].row22, field, sizeof(hr_comp[i].row22) - 1);
              hr_comp[i].row22[sizeof(hr_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(hr_comp[i].row23, field, sizeof(hr_comp[i].row23) - 1);
              hr_comp[i].row23[sizeof(hr_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(hr_comp[i].row24, field, sizeof(hr_comp[i].row24) - 1);
              hr_comp[i].row24[sizeof(hr_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(hr_comp[i].row25, field, sizeof(hr_comp[i].row25) - 1);
              hr_comp[i].row25[sizeof(hr_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(hr_comp[i].row26, field, sizeof(hr_comp[i].row26) - 1);
              hr_comp[i].row26[sizeof(hr_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(hr_comp[i].row27, field, sizeof(hr_comp[i].row27) - 1);
              hr_comp[i].row27[sizeof(hr_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(hr_comp[i].row28, field, sizeof(hr_comp[i].row28) - 1);
              hr_comp[i].row28[sizeof(hr_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(hr_comp[i].row29, field, sizeof(hr_comp[i].row29) - 1);
              hr_comp[i].row29[sizeof(hr_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(hr_comp[i].row30, field, sizeof(hr_comp[i].row30) - 1);
              hr_comp[i].row30[sizeof(hr_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(hr_comp[i].row31, field, sizeof(hr_comp[i].row31) - 1);
              hr_comp[i].row31[sizeof(hr_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(hr_comp[i].row32, field, sizeof(hr_comp[i].row32) - 1);
              hr_comp[i].row32[sizeof(hr_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(hr_comp[i].row33, field, sizeof(hr_comp[i].row33) - 1);
              hr_comp[i].row33[sizeof(hr_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(hr_comp[i].row34, field, sizeof(hr_comp[i].row34) - 1);
              hr_comp[i].row34[sizeof(hr_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(hr_comp[i].row35, field, sizeof(hr_comp[i].row35) - 1);
              hr_comp[i].row35[sizeof(hr_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(hr_comp[i].row36, field, sizeof(hr_comp[i].row36) - 1);
              hr_comp[i].row36[sizeof(hr_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(hr_comp[i].row37, field, sizeof(hr_comp[i].row37) - 1);
              hr_comp[i].row37[sizeof(hr_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(hr_comp[i].row38, field, sizeof(hr_comp[i].row38) - 1);
              hr_comp[i].row38[sizeof(hr_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(hr_comp[i].row39, field, sizeof(hr_comp[i].row39) - 1);
              hr_comp[i].row39[sizeof(hr_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(hr_comp[i].row40, field, sizeof(hr_comp[i].row40) - 1);
              hr_comp[i].row40[sizeof(hr_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(hr_comp[i].row41, field, sizeof(hr_comp[i].row41) - 1);
              hr_comp[i].row41[sizeof(hr_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(hr_comp[i].row42, field, sizeof(hr_comp[i].row42) - 1);
              hr_comp[i].row42[sizeof(hr_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(hr_comp[i].row43, field, sizeof(hr_comp[i].row43) - 1);
              hr_comp[i].row43[sizeof(hr_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(hr_comp[i].row44, field, sizeof(hr_comp[i].row44) - 1);
              hr_comp[i].row44[sizeof(hr_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(hr_comp[i].row45, field, sizeof(hr_comp[i].row45) - 1);
              hr_comp[i].row45[sizeof(hr_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file1)) {
          char *field = strtok(line, ",");
          int field_count = 0;

          while (field) {
            if (field_count == 0) {
              strncpy(hr_des[i].firm, field, sizeof(hr_des[i].firm) - 1);
              hr_des[i].firm[sizeof(hr_des[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(hr_des[i].name, field, sizeof(hr_des[i].name) - 1);
              hr_des[i].name[sizeof(hr_des[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(hr_des[i].login, field, sizeof(hr_des[i].login) - 1);
              hr_des[i].login[sizeof(hr_des[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(hr_des[i].row1, field, sizeof(hr_des[i].row1) - 1);
              hr_des[i].row1[sizeof(hr_des[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(hr_des[i].row2, field, sizeof(hr_des[i].row2) - 1);
              hr_des[i].row2[sizeof(hr_des[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(hr_des[i].row3, field, sizeof(hr_des[i].row3) - 1);
              hr_des[i].row3[sizeof(hr_des[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(hr_des[i].row4, field, sizeof(hr_des[i].row4) - 1);
              hr_des[i].row4[sizeof(hr_des[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(hr_des[i].row5, field, sizeof(hr_des[i].row5) - 1);
              hr_des[i].row5[sizeof(hr_des[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(hr_des[i].row6, field, sizeof(hr_des[i].row6) - 1);
              hr_des[i].row6[sizeof(hr_des[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(hr_des[i].row7, field, sizeof(hr_des[i].row7) - 1);
              hr_des[i].row7[sizeof(hr_des[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(hr_des[i].row8, field, sizeof(hr_des[i].row8) - 1);
              hr_des[i].row8[sizeof(hr_des[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(hr_des[i].row9, field, sizeof(hr_des[i].row9) - 1);
              hr_des[i].row9[sizeof(hr_des[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(hr_des[i].row10, field, sizeof(hr_des[i].row10) - 1);
              hr_des[i].row10[sizeof(hr_des[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(hr_des[i].row11, field, sizeof(hr_des[i].row11) - 1);
              hr_des[i].row11[sizeof(hr_des[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(hr_des[i].row12, field, sizeof(hr_des[i].row12) - 1);
              hr_des[i].row12[sizeof(hr_des[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(hr_des[i].row13, field, sizeof(hr_des[i].row13) - 1);
              hr_des[i].row13[sizeof(hr_des[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(hr_des[i].row14, field, sizeof(hr_des[i].row14) - 1);
              hr_des[i].row14[sizeof(hr_des[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(hr_des[i].row15, field, sizeof(hr_des[i].row15) - 1);
              hr_des[i].row15[sizeof(hr_des[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(hr_des[i].row16, field, sizeof(hr_des[i].row16) - 1);
              hr_des[i].row16[sizeof(hr_des[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(hr_des[i].row17, field, sizeof(hr_des[i].row17) - 1);
              hr_des[i].row17[sizeof(hr_des[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(hr_des[i].row18, field, sizeof(hr_des[i].row18) - 1);
              hr_des[i].row18[sizeof(hr_des[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(hr_des[i].row19, field, sizeof(hr_des[i].row19) - 1);
              hr_des[i].row19[sizeof(hr_des[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(hr_des[i].row20, field, sizeof(hr_des[i].row20) - 1);
              hr_des[i].row20[sizeof(hr_des[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(hr_des[i].row21, field, sizeof(hr_des[i].row21) - 1);
              hr_des[i].row21[sizeof(hr_des[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(hr_des[i].row22, field, sizeof(hr_des[i].row22) - 1);
              hr_des[i].row22[sizeof(hr_des[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(hr_des[i].row23, field, sizeof(hr_des[i].row23) - 1);
              hr_des[i].row23[sizeof(hr_des[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(hr_des[i].row24, field, sizeof(hr_des[i].row24) - 1);
              hr_des[i].row24[sizeof(hr_des[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(hr_des[i].row25, field, sizeof(hr_des[i].row25) - 1);
              hr_des[i].row25[sizeof(hr_des[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(hr_des[i].row26, field, sizeof(hr_des[i].row26) - 1);
              hr_des[i].row26[sizeof(hr_des[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(hr_des[i].row27, field, sizeof(hr_des[i].row27) - 1);
              hr_des[i].row27[sizeof(hr_des[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(hr_des[i].row28, field, sizeof(hr_des[i].row28) - 1);
              hr_des[i].row28[sizeof(hr_des[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(hr_des[i].row29, field, sizeof(hr_des[i].row29) - 1);
              hr_des[i].row29[sizeof(hr_des[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(hr_des[i].row30, field, sizeof(hr_des[i].row30) - 1);
              hr_des[i].row30[sizeof(hr_des[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(hr_des[i].row31, field, sizeof(hr_des[i].row31) - 1);
              hr_des[i].row31[sizeof(hr_des[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(hr_des[i].row32, field, sizeof(hr_des[i].row32) - 1);
              hr_des[i].row32[sizeof(hr_des[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(hr_des[i].row33, field, sizeof(hr_des[i].row33) - 1);
              hr_des[i].row33[sizeof(hr_des[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(hr_des[i].row34, field, sizeof(hr_des[i].row34) - 1);
              hr_des[i].row34[sizeof(hr_des[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(hr_des[i].row35, field, sizeof(hr_des[i].row35) - 1);
              hr_des[i].row35[sizeof(hr_des[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(hr_des[i].row36, field, sizeof(hr_des[i].row36) - 1);
              hr_des[i].row36[sizeof(hr_des[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(hr_des[i].row37, field, sizeof(hr_des[i].row37) - 1);
              hr_des[i].row37[sizeof(hr_des[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(hr_des[i].row38, field, sizeof(hr_des[i].row38) - 1);
              hr_des[i].row38[sizeof(hr_des[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(hr_des[i].row39, field, sizeof(hr_des[i].row39) - 1);
              hr_des[i].row39[sizeof(hr_des[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(hr_des[i].row40, field, sizeof(hr_des[i].row40) - 1);
              hr_des[i].row40[sizeof(hr_des[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(hr_des[i].row41, field, sizeof(hr_des[i].row41) - 1);
              hr_des[i].row41[sizeof(hr_des[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(hr_des[i].row42, field, sizeof(hr_des[i].row42) - 1);
              hr_des[i].row42[sizeof(hr_des[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(hr_des[i].row43, field, sizeof(hr_des[i].row43) - 1);
              hr_des[i].row43[sizeof(hr_des[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(hr_des[i].row44, field, sizeof(hr_des[i].row44) - 1);
              hr_des[i].row44[sizeof(hr_des[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(hr_des[i].row45, field, sizeof(hr_des[i].row45) - 1);
              hr_des[i].row45[sizeof(hr_des[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file2)) {
          char *field = strtok(line, ",");
          int field_count = 0;
          while (field) {
            if (field_count == 0) {
              strncpy(ap_comp[i].firm, field, sizeof(ap_comp[i].firm) - 1);
              ap_comp[i].firm[sizeof(ap_comp[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(ap_comp[i].name, field, sizeof(ap_comp[i].name) - 1);
              ap_comp[i].name[sizeof(ap_comp[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(ap_comp[i].login, field, sizeof(ap_comp[i].login) - 1);
              ap_comp[i].login[sizeof(ap_comp[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(ap_comp[i].row1, field, sizeof(ap_comp[i].row1) - 1);
              ap_comp[i].row1[sizeof(ap_comp[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(ap_comp[i].row2, field, sizeof(ap_comp[i].row2) - 1);
              ap_comp[i].row2[sizeof(ap_comp[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(ap_comp[i].row3, field, sizeof(ap_comp[i].row3) - 1);
              ap_comp[i].row3[sizeof(ap_comp[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(ap_comp[i].row4, field, sizeof(ap_comp[i].row4) - 1);
              ap_comp[i].row4[sizeof(ap_comp[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(ap_comp[i].row5, field, sizeof(ap_comp[i].row5) - 1);
              ap_comp[i].row5[sizeof(ap_comp[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(ap_comp[i].row6, field, sizeof(ap_comp[i].row6) - 1);
              ap_comp[i].row6[sizeof(ap_comp[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(ap_comp[i].row7, field, sizeof(ap_comp[i].row7) - 1);
              ap_comp[i].row7[sizeof(ap_comp[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(ap_comp[i].row8, field, sizeof(ap_comp[i].row8) - 1);
              ap_comp[i].row8[sizeof(ap_comp[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(ap_comp[i].row9, field, sizeof(ap_comp[i].row9) - 1);
              ap_comp[i].row9[sizeof(ap_comp[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(ap_comp[i].row10, field, sizeof(ap_comp[i].row10) - 1);
              ap_comp[i].row10[sizeof(ap_comp[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(ap_comp[i].row11, field, sizeof(ap_comp[i].row11) - 1);
              ap_comp[i].row11[sizeof(ap_comp[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(ap_comp[i].row12, field, sizeof(ap_comp[i].row12) - 1);
              ap_comp[i].row12[sizeof(ap_comp[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(ap_comp[i].row13, field, sizeof(ap_comp[i].row13) - 1);
              ap_comp[i].row13[sizeof(ap_comp[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(ap_comp[i].row14, field, sizeof(ap_comp[i].row14) - 1);
              ap_comp[i].row14[sizeof(ap_comp[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(ap_comp[i].row15, field, sizeof(ap_comp[i].row15) - 1);
              ap_comp[i].row15[sizeof(ap_comp[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(ap_comp[i].row16, field, sizeof(ap_comp[i].row16) - 1);
              ap_comp[i].row16[sizeof(ap_comp[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(ap_comp[i].row17, field, sizeof(ap_comp[i].row17) - 1);
              ap_comp[i].row17[sizeof(ap_comp[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(ap_comp[i].row18, field, sizeof(ap_comp[i].row18) - 1);
              ap_comp[i].row18[sizeof(ap_comp[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(ap_comp[i].row19, field, sizeof(ap_comp[i].row19) - 1);
              ap_comp[i].row19[sizeof(ap_comp[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(ap_comp[i].row20, field, sizeof(ap_comp[i].row20) - 1);
              ap_comp[i].row20[sizeof(ap_comp[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(ap_comp[i].row21, field, sizeof(ap_comp[i].row21) - 1);
              ap_comp[i].row21[sizeof(ap_comp[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(ap_comp[i].row22, field, sizeof(ap_comp[i].row22) - 1);
              ap_comp[i].row22[sizeof(ap_comp[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(ap_comp[i].row23, field, sizeof(ap_comp[i].row23) - 1);
              ap_comp[i].row23[sizeof(ap_comp[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(ap_comp[i].row24, field, sizeof(ap_comp[i].row24) - 1);
              ap_comp[i].row24[sizeof(ap_comp[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(ap_comp[i].row25, field, sizeof(ap_comp[i].row25) - 1);
              ap_comp[i].row25[sizeof(ap_comp[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(ap_comp[i].row26, field, sizeof(ap_comp[i].row26) - 1);
              ap_comp[i].row26[sizeof(ap_comp[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(ap_comp[i].row27, field, sizeof(ap_comp[i].row27) - 1);
              ap_comp[i].row27[sizeof(ap_comp[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(ap_comp[i].row28, field, sizeof(ap_comp[i].row28) - 1);
              ap_comp[i].row28[sizeof(ap_comp[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(ap_comp[i].row29, field, sizeof(ap_comp[i].row29) - 1);
              ap_comp[i].row29[sizeof(ap_comp[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(ap_comp[i].row30, field, sizeof(ap_comp[i].row30) - 1);
              ap_comp[i].row30[sizeof(ap_comp[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(ap_comp[i].row31, field, sizeof(ap_comp[i].row31) - 1);
              ap_comp[i].row31[sizeof(ap_comp[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(ap_comp[i].row32, field, sizeof(ap_comp[i].row32) - 1);
              ap_comp[i].row32[sizeof(ap_comp[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(ap_comp[i].row33, field, sizeof(ap_comp[i].row33) - 1);
              ap_comp[i].row33[sizeof(ap_comp[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(ap_comp[i].row34, field, sizeof(ap_comp[i].row34) - 1);
              ap_comp[i].row34[sizeof(ap_comp[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(ap_comp[i].row35, field, sizeof(ap_comp[i].row35) - 1);
              ap_comp[i].row35[sizeof(ap_comp[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(ap_comp[i].row36, field, sizeof(ap_comp[i].row36) - 1);
              ap_comp[i].row36[sizeof(ap_comp[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(ap_comp[i].row37, field, sizeof(ap_comp[i].row37) - 1);
              ap_comp[i].row37[sizeof(ap_comp[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(ap_comp[i].row38, field, sizeof(ap_comp[i].row38) - 1);
              ap_comp[i].row38[sizeof(ap_comp[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(ap_comp[i].row39, field, sizeof(ap_comp[i].row39) - 1);
              ap_comp[i].row39[sizeof(ap_comp[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(ap_comp[i].row40, field, sizeof(ap_comp[i].row40) - 1);
              ap_comp[i].row40[sizeof(ap_comp[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(ap_comp[i].row41, field, sizeof(ap_comp[i].row41) - 1);
              ap_comp[i].row41[sizeof(ap_comp[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(ap_comp[i].row42, field, sizeof(ap_comp[i].row42) - 1);
              ap_comp[i].row42[sizeof(ap_comp[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(ap_comp[i].row43, field, sizeof(ap_comp[i].row43) - 1);
              ap_comp[i].row43[sizeof(ap_comp[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(ap_comp[i].row44, field, sizeof(ap_comp[i].row44) - 1);
              ap_comp[i].row44[sizeof(ap_comp[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(ap_comp[i].row45, field, sizeof(ap_comp[i].row45) - 1);
              ap_comp[i].row45[sizeof(ap_comp[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }
        i = 0;
        while (fgets(line, sizeof(line), file3)) {
          char *field = strtok(line, ",");
          int field_count = 0;

          while (field) {
            if (field_count == 0) {
              strncpy(ap_des[i].firm, field, sizeof(ap_des[i].firm) - 1);
              ap_des[i].firm[sizeof(ap_des[i].firm) - 1] = '\0';
            }
            if (field_count == 1) {
              strncpy(ap_des[i].name, field, sizeof(ap_des[i].name) - 1);
              ap_des[i].name[sizeof(ap_des[i].name) - 1] = '\0';
            }
            if (field_count == 2) {
              strncpy(ap_des[i].login, field, sizeof(ap_des[i].login) - 1);
              ap_des[i].login[sizeof(ap_des[i].login) - 1] = '\0';
            }
            if (field_count == 3) {
              strncpy(ap_des[i].row1, field, sizeof(ap_des[i].row1) - 1);
              ap_des[i].row1[sizeof(ap_des[i].row1) - 1] = '\0';
            }
            if (field_count == 4) {
              strncpy(ap_des[i].row2, field, sizeof(ap_des[i].row2) - 1);
              ap_des[i].row2[sizeof(ap_des[i].row2) - 1] = '\0';
            }
            if (field_count == 5) {
              strncpy(ap_des[i].row3, field, sizeof(ap_des[i].row3) - 1);
              ap_des[i].row3[sizeof(ap_des[i].row3) - 1] = '\0';
            }
            if (field_count == 6) {
              strncpy(ap_des[i].row4, field, sizeof(ap_des[i].row4) - 1);
              ap_des[i].row4[sizeof(ap_des[i].row4) - 1] = '\0';
            }
            if (field_count == 7) {
              strncpy(ap_des[i].row5, field, sizeof(ap_des[i].row5) - 1);
              ap_des[i].row5[sizeof(ap_des[i].row5) - 1] = '\0';
            }
            if (field_count == 8) {
              strncpy(ap_des[i].row6, field, sizeof(ap_des[i].row6) - 1);
              ap_des[i].row6[sizeof(ap_des[i].row6) - 1] = '\0';
            }
            if (field_count == 9) {
              strncpy(ap_des[i].row7, field, sizeof(ap_des[i].row7) - 1);
              ap_des[i].row7[sizeof(ap_des[i].row7) - 1] = '\0';
            }
            if (field_count == 10) {
              strncpy(ap_des[i].row8, field, sizeof(ap_des[i].row8) - 1);
              ap_des[i].row8[sizeof(ap_des[i].row8) - 1] = '\0';
            }
            if (field_count == 11) {
              strncpy(ap_des[i].row9, field, sizeof(ap_des[i].row9) - 1);
              ap_des[i].row9[sizeof(ap_des[i].row9) - 1] = '\0';
            }
            if (field_count == 12) {
              strncpy(ap_des[i].row10, field, sizeof(ap_des[i].row10) - 1);
              ap_des[i].row10[sizeof(ap_des[i].row10) - 1] = '\0';
            }
            if (field_count == 13) {
              strncpy(ap_des[i].row11, field, sizeof(ap_des[i].row11) - 1);
              ap_des[i].row11[sizeof(ap_des[i].row11) - 1] = '\0';
            }
            if (field_count == 14) {
              strncpy(ap_des[i].row12, field, sizeof(ap_des[i].row12) - 1);
              ap_des[i].row12[sizeof(ap_des[i].row12) - 1] = '\0';
            }
            if (field_count == 15) {
              strncpy(ap_des[i].row13, field, sizeof(ap_des[i].row13) - 1);
              ap_des[i].row13[sizeof(ap_des[i].row13) - 1] = '\0';
            }
            if (field_count == 16) {
              strncpy(ap_des[i].row14, field, sizeof(ap_des[i].row14) - 1);
              ap_des[i].row14[sizeof(ap_des[i].row14) - 1] = '\0';
            }
            if (field_count == 17) {
              strncpy(ap_des[i].row15, field, sizeof(ap_des[i].row15) - 1);
              ap_des[i].row15[sizeof(ap_des[i].row15) - 1] = '\0';
            }
            if (field_count == 18) {
              strncpy(ap_des[i].row16, field, sizeof(ap_des[i].row16) - 1);
              ap_des[i].row16[sizeof(ap_des[i].row16) - 1] = '\0';
            }
            if (field_count == 19) {
              strncpy(ap_des[i].row17, field, sizeof(ap_des[i].row17) - 1);
              ap_des[i].row17[sizeof(ap_des[i].row17) - 1] = '\0';
            }
            if (field_count == 20) {
              strncpy(ap_des[i].row18, field, sizeof(ap_des[i].row18) - 1);
              ap_des[i].row18[sizeof(ap_des[i].row18) - 1] = '\0';
            }
            if (field_count == 21) {
              strncpy(ap_des[i].row19, field, sizeof(ap_des[i].row19) - 1);
              ap_des[i].row19[sizeof(ap_des[i].row19) - 1] = '\0';
            }
            if (field_count == 22) {
              strncpy(ap_des[i].row20, field, sizeof(ap_des[i].row20) - 1);
              ap_des[i].row20[sizeof(ap_des[i].row20) - 1] = '\0';
            }
            if (field_count == 23) {
              strncpy(ap_des[i].row21, field, sizeof(ap_des[i].row21) - 1);
              ap_des[i].row21[sizeof(ap_des[i].row21) - 1] = '\0';
            }
            if (field_count == 24) {
              strncpy(ap_des[i].row22, field, sizeof(ap_des[i].row22) - 1);
              ap_des[i].row22[sizeof(ap_des[i].row22) - 1] = '\0';
            }
            if (field_count == 25) {
              strncpy(ap_des[i].row23, field, sizeof(ap_des[i].row23) - 1);
              ap_des[i].row23[sizeof(ap_des[i].row23) - 1] = '\0';
            }
            if (field_count == 26) {
              strncpy(ap_des[i].row24, field, sizeof(ap_des[i].row24) - 1);
              ap_des[i].row24[sizeof(ap_des[i].row24) - 1] = '\0';
            }
            if (field_count == 27) {
              strncpy(ap_des[i].row25, field, sizeof(ap_des[i].row25) - 1);
              ap_des[i].row25[sizeof(ap_des[i].row25) - 1] = '\0';
            }
            if (field_count == 28) {
              strncpy(ap_des[i].row26, field, sizeof(ap_des[i].row26) - 1);
              ap_des[i].row26[sizeof(ap_des[i].row26) - 1] = '\0';
            }
            if (field_count == 29) {
              strncpy(ap_des[i].row27, field, sizeof(ap_des[i].row27) - 1);
              ap_des[i].row27[sizeof(ap_des[i].row27) - 1] = '\0';
            }
            if (field_count == 30) {
              strncpy(ap_des[i].row28, field, sizeof(ap_des[i].row28) - 1);
              ap_des[i].row28[sizeof(ap_des[i].row28) - 1] = '\0';
            }
            if (field_count == 31) {
              strncpy(ap_des[i].row29, field, sizeof(ap_des[i].row29) - 1);
              ap_des[i].row29[sizeof(ap_des[i].row29) - 1] = '\0';
            }
            if (field_count == 32) {
              strncpy(ap_des[i].row30, field, sizeof(ap_des[i].row30) - 1);
              ap_des[i].row30[sizeof(ap_des[i].row30) - 1] = '\0';
            }
            if (field_count == 33) {
              strncpy(ap_des[i].row31, field, sizeof(ap_des[i].row31) - 1);
              ap_des[i].row31[sizeof(ap_des[i].row31) - 1] = '\0';
            }
            if (field_count == 34) {
              strncpy(ap_des[i].row32, field, sizeof(ap_des[i].row32) - 1);
              ap_des[i].row32[sizeof(ap_des[i].row32) - 1] = '\0';
            }
            if (field_count == 35) {
              strncpy(ap_des[i].row33, field, sizeof(ap_des[i].row33) - 1);
              ap_des[i].row33[sizeof(ap_des[i].row33) - 1] = '\0';
            }
            if (field_count == 36) {
              strncpy(ap_des[i].row34, field, sizeof(ap_des[i].row34) - 1);
              ap_des[i].row34[sizeof(ap_des[i].row34) - 1] = '\0';
            }
            if (field_count == 37) {
              strncpy(ap_des[i].row35, field, sizeof(ap_des[i].row35) - 1);
              ap_des[i].row35[sizeof(ap_des[i].row35) - 1] = '\0';
            }
            if (field_count == 38) {
              strncpy(ap_des[i].row36, field, sizeof(ap_des[i].row36) - 1);
              ap_des[i].row36[sizeof(ap_des[i].row36) - 1] = '\0';
            }
            if (field_count == 39) {
              strncpy(ap_des[i].row37, field, sizeof(ap_des[i].row37) - 1);
              ap_des[i].row37[sizeof(ap_des[i].row37) - 1] = '\0';
            }
            if (field_count == 40) {
              strncpy(ap_des[i].row38, field, sizeof(ap_des[i].row38) - 1);
              ap_des[i].row38[sizeof(ap_des[i].row38) - 1] = '\0';
            }
            if (field_count == 41) {
              strncpy(ap_des[i].row39, field, sizeof(ap_des[i].row39) - 1);
              ap_des[i].row39[sizeof(ap_des[i].row39) - 1] = '\0';
            }
            if (field_count == 42) {
              strncpy(ap_des[i].row40, field, sizeof(ap_des[i].row40) - 1);
              ap_des[i].row40[sizeof(ap_des[i].row40) - 1] = '\0';
            }
            if (field_count == 43) {
              strncpy(ap_des[i].row41, field, sizeof(ap_des[i].row41) - 1);
              ap_des[i].row41[sizeof(ap_des[i].row41) - 1] = '\0';
            }
            if (field_count == 44) {
              strncpy(ap_des[i].row42, field, sizeof(ap_des[i].row42) - 1);
              ap_des[i].row42[sizeof(ap_des[i].row42) - 1] = '\0';
            }
            if (field_count == 45) {
              strncpy(ap_des[i].row43, field, sizeof(ap_des[i].row43) - 1);
              ap_des[i].row43[sizeof(ap_des[i].row43) - 1] = '\0';
            }
            if (field_count == 46) {
              strncpy(ap_des[i].row44, field, sizeof(ap_des[i].row44) - 1);
              ap_des[i].row44[sizeof(ap_des[i].row44) - 1] = '\0';
            }
            if (field_count == 47) {
              strncpy(ap_des[i].row45, field, sizeof(ap_des[i].row45) - 1);
              ap_des[i].row45[sizeof(ap_des[i].row45) - 1] = '\0';
            }

            field = strtok(NULL, ",");
            field_count++;
          }
          i++;
        }

        char ap10[30], apjob10[30];
        printf("\nEnter name of applicant:");
        scanf("%s", ap10);
        printf("\nEnter Job Position number:");
        scanf("%s", apjob10);
        // sum for comp sum , sum1 for des sum
        int flag = 0, sum = 0, k = 0, sum1 = 0, flag2 = 0;
        for (int y = 0; y < i / 2; y++) {
          // to find applicant details from compulsory file;
          if ((strcmp(ap_comp[y].name, ap10) == 0) &&
              (strcmp(ap_comp[y].row2, apjob10) == 0)) {
            printf("\nFound applicant details!.");
            flag = 1;
            // matching details of the compulsory file
            for (int y1 = 0; y1 < i; y1 = y1 + 2) {
              sum = 0;
              sum1 = 0;
              if ((strcmp(ap_comp[y].row4, hr_comp[y1].row4) == 0) &&
                  (strcmp(ap_comp[y].row1, hr_comp[y1].row1) == 0) &&
                  (strcmp(ap_comp[y].row2, hr_comp[y1].row2) == 0) &&
                  (strcmp(ap_comp[y].row5, hr_comp[y1].row5) == 0) &&
                  (strcmp(ap_comp[y].row7, hr_comp[y1].row7) == 0) &&
                  (strcmp(ap_comp[y].row8, hr_comp[y1].row8) == 0) &&
                  (strcmp(ap_comp[y].row10, hr_comp[y1].row10) == 0) &&
                  (strcmp(ap_comp[y].row11, hr_comp[y1].row11) == 0) &&
                  (strcmp(ap_comp[y].row13, hr_comp[y1].row13) == 0) &&
                  (strcmp(ap_comp[y].row14, hr_comp[y1].row14) == 0) &&
                  (strcmp(ap_comp[y].row16, hr_comp[y1].row16) == 0) &&
                  (strcmp(ap_comp[y].row17, hr_comp[y1].row17) == 0) &&
                  (strcmp(ap_comp[y].row19, hr_comp[y1].row19) == 0) &&
                  (strcmp(ap_comp[y].row20, hr_comp[y1].row20) == 0) &&
                  (strcmp(ap_comp[y].row22, hr_comp[y1].row22) == 0) &&
                  (strcmp(ap_comp[y].row23, hr_comp[y1].row23) == 0) &&
                  (strcmp(ap_comp[y].row25, hr_comp[y1].row25) == 0) &&
                  (strcmp(ap_comp[y].row26, hr_comp[y1].row26) == 0) &&
                  (strcmp(ap_comp[y].row28, hr_comp[y1].row28) == 0) &&
                  (strcmp(ap_comp[y].row29, hr_comp[y1].row29) == 0) &&
                  (strcmp(ap_comp[y].row31, hr_comp[y1].row31) == 0) &&
                  (strcmp(ap_comp[y].row32, hr_comp[y1].row32) == 0)) {
                flag2 = 1;
                sum = atof(hr_comp[y1].row3) + atof(hr_comp[y1].row6) +
                      atof(hr_comp[y1].row9) + atof(hr_comp[y1].row12) +
                      atof(hr_comp[y1].row15) + atof(hr_comp[y1].row18) +
                      atof(hr_comp[y1].row21) + atof(hr_comp[y1].row24) +
                      atof(hr_comp[y1].row27) + atof(hr_comp[y1].row30);
                ap_suggestions[k].compsum = sum;
                strcpy(ap_suggestions[k].name, hr_comp[y1].name);
                strcpy(ap_suggestions[k].firm, hr_comp[y1].firm);
                char email[30];
                strcpy(email, hr_comp[y1].name);
                strcat(email, "@");
                strcat(email, hr_comp[y1].firm);
                strcat(email, ".com");
                strcpy(ap_suggestions[k].email, email);
                if ((strcmp(ap_des[y].row1, hr_des[y1].row1) == 0) &&
                    (strcmp(ap_des[y].row2, hr_des[y1].row2) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row3);
                }
                if ((strcmp(ap_des[y].row4, hr_des[y1].row4) == 0) &&
                    (strcmp(ap_des[y].row5, hr_des[y1].row5) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row6);
                }
                if ((strcmp(ap_des[y].row7, hr_des[y1].row7) == 0) &&
                    (strcmp(ap_des[y].row8, hr_des[y1].row8) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row9);
                }
                if ((strcmp(ap_des[y].row10, hr_des[y1].row10) == 0) &&
                    (strcmp(ap_des[y].row11, hr_des[y1].row11) == 0)) {
                  sum1 = sum1 + atof(hr_des[y].row12);
                }
                if ((strcmp(ap_des[y].row13, hr_des[y1].row13) == 0) &&
                    (strcmp(ap_des[y].row14, hr_des[y1].row14) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row15);
                }
                if ((strcmp(ap_des[y].row16, hr_des[y1].row16) == 0) &&
                    (strcmp(ap_des[y].row17, hr_des[y1].row17) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row18);
                }
                if ((strcmp(ap_des[y].row19, hr_des[y1].row19) == 0) &&
                    (strcmp(ap_des[y].row20, hr_des[y1].row20) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row21);
                }
                if ((strcmp(ap_des[y].row22, hr_des[y1].row22) == 0) &&
                    (strcmp(ap_des[y].row23, hr_des[y1].row23) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row24);
                }
                if ((strcmp(ap_des[y].row25, hr_des[y1].row25) == 0) &&
                    (strcmp(ap_des[y].row26, hr_des[y1].row26) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row27);
                }
                if ((strcmp(ap_des[y].row28, hr_des[y1].row28) == 0) &&
                    (strcmp(ap_des[y].row29, hr_des[y1].row29) == 0)) {
                  sum1 = sum1 + atof(hr_des[y1].row30);
                }
                ap_suggestions[k].dessum = sum1;
                ap_suggestions[k].totalsum = sum1 + sum;
                k++;
              }
            }
          }
        }

        /*if((strcmp(hr_comp[y].row31,ap_comp[y].row31) == 0)
           &&(strcmp(hr_comp[y].row32, ap_comp[y].row32) == 0)
           &&(strcmp(hr_comp[y].row33, ap_comp[y].row33) == 0)
           &&(strcmp(hr_comp[y].row34, ap_comp[y].row34) == 0)
           &&(strcmp(hr_comp[y].row35, ap_comp[y].row35) == 0)
           &&(strcmp(hr_comp[y].row36, ap_comp[y].row36) == 0)
           &&(strcmp(hr_comp[y].row37, ap_comp[y].row37) == 0)
           &&(strcmp(hr_comp[y].row38, ap_comp[y].row38) == 0)
           &&(strcmp(hr_comp[y].row39, ap_comp[y].row39) == 0)
           &&(strcmp(hr_comp[y].row40, ap_comp[y].row40) == 0)
           &&(strcmp(hr_comp[y].row41, ap_comp[y].row41) == 0)
           &&(strcmp(hr_comp[y].row42, ap_comp[y].row42) == 0)
           &&(strcmp(hr_comp[y].row43, ap_comp[y].row43) == 0)
           &&(strcmp(hr_comp[y].row44, ap_comp[y].row44) == 0)
           &&(strcmp(hr_comp[y].row45, ap_comp[y].row45) == 0)){ printf("\nall
           fields matched matched");}
                  }
                */
        fclose(file);
        fclose(file1);
        fclose(file2);
        fclose(file3);
        if (flag == 0) {
          printf("\nSorry ,above mentioned details along with Job Profile not "
                 "found.\n");
        }
        if (flag2 == 0) {
          printf("\nNo suitable job vacancy is currently available.\n");
        }
        if (flag2 == 1) {

          for (int x1 = 1; x1 < k; x1++) {

            for (int x2 = 0; x2 < k - x1; x2++) {
              if (ap_suggestions[x2].totalsum >
                  ap_suggestions[x2 + 1].totalsum) {
                temp1 = ap_suggestions[x2];
                ap_suggestions[x2] = ap_suggestions[x2 + 1];
                ap_suggestions[x2 + 1] = temp1;
              }
            }
          }
          printf("\n\n---------------------------------------\n\n");
          printf("\nTop three suitable JOb Vacancies for the mentioned JOB "
                 "PROFILE are as follows:");
          for (int x1 = 0; x1 < 3; x1++) {
            printf("\nRank %d.\tName:%s\tFirm:%s\tEmail:%s\t", x1 + 1,
                   ap_suggestions[x1].name, ap_suggestions[x1].firm,
                   ap_suggestions[x1].email);
          }
          FILE *file5 = fopen("ap_ranks.csv", "a");
          fprintf(file5, "%s,%s", ap10, apjob10);
          printf("\nEnter number of vacancies you would like to apply:");
          int accept;
          scanf("%d", &accept);
          for (int y4 = 0; y4 < accept; y4++) {
            printf(
                "\nEnter Rank number of the vacancy you would like to continue "
                "and initiate application process with(Rank number 1,2..):");
            int rank;
            scanf("%d", &rank);
            if (rank == 1) {
              fprintf(file5, ",%s,%s,%s", ap_suggestions[0].firm,
                      ap_suggestions[0].name, ap_suggestions[0].email);
            }
            if (rank == 2) {
              fprintf(file5, ",%s,%s,%s", ap_suggestions[1].firm,
                      ap_suggestions[1].name, ap_suggestions[1].email);
            }

            if (rank == 3) {
              fprintf(file5, ",%s,%s,%s", ap_suggestions[2].firm,
                      ap_suggestions[2].name, ap_suggestions[2].email);
            }
          }
          fprintf(file5, "\n");
          printf("\nPreferences noted.\n");
          fclose(file5);
        }
      }

      else if (choice2 == 4) {
        FILE *file5 = fopen("ap_ranks.csv", "r");
        struct hr_suggestions hr_suggestions[3];
        char name11[40], job11[3];
        // flag3 to navigate if profile found
        int flag3 = 0;
        printf("\nEnter name of applicant:");
        scanf("%s", name11);
        printf("\nEnter Job Position number:");
        scanf("%s", job11);
        char line[256];
        char *token;

        // Read each line from the file
        while (fgets(line, sizeof(line), file5)) {
          // Create a copy of the line for tokenization
          char line_copy[256];
          strcpy(line_copy, line);

          // Split the line into tokens
          token = strtok(line_copy, ",");

          // Check if the first three values match the desired values
          if (token != NULL && strcmp(token, name11) == 0) {
            token = strtok(NULL, ",");
            if (token != NULL && strcmp(token, job11) == 0) {
              flag3 = 1;
              printf("\nDetails about the HR manager along with the JOB "
                     "position entered and profiles accpeted \n");

              // Print all details in the found row
              token = strtok(line, ",");
              while (token != NULL) {
                printf("%s\n", token);
                token = strtok(NULL, ",");
              }
              break; // Exit the loop after finding the row
            }
          }
        }

        // Close the file
        fclose(file5);
        if (flag3 == 0) {
          printf("\nSorry matching not initiated!\n");
        }
      }

      else if (choice2 == 5) {
        printf(
            "\n\nThank you so much for visiting our portal. We hope that our "
            "portal opened new doors to exciting opportunities.Good "
            "luck:)\n\n");
        printf("\n\n---------------------------------------\n\n");
        return 1;
      }
    }
  }

  else {
    printf("\nRole not recognised,user not authorised!");
    printf("\nExiting system!");
    return 1;
  }
}
