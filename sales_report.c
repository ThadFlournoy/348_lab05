#include <stdio.h>

#define NUM_MONTHS 12

// Function declarations
void printMonthlySalesReport(float sales[], const char *months[]);
void printSalesSummaryReport(float sales[], const char *months[]);
void printSixMonthMovingAverageReport(float sales[]);
void printSalesReportHighestToLowest(float sales[], const char *months[]);

int main() {
    // Sales data
    float sales[NUM_MONTHS] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67,
        60200.22, 72400.31, 56210.89, 67230.84, 68233.12,
        80950.34, 95225.22
    };

    // Corresponding month names
    const char *months[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Print the reports
    printf("Monthly Sales Report for 2024\n");
    printf("-----------------------------\n");
    printMonthlySalesReport(sales, months);

    printf("\nSales Summary Report\n");
    printf("--------------------\n");
    printSalesSummaryReport(sales, months);

    printf("\nSix-Month Moving Average Report\n");
    printf("-------------------------------\n");
    printSixMonthMovingAverageReport(sales);

    printf("\nSales Report (Highest to Lowest)\n");
    printf("-------------------------------\n");
    printSalesReportHighestToLowest(sales, months);

    return 0;
}

// Function to print the Monthly Sales Report
void printMonthlySalesReport(float sales[], const char *months[]) {
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%.2f\n", months[i], sales[i]);
    }
}

// Function to print the Sales Summary Report
void printSalesSummaryReport(float sales[], const char *months[]) {
    float min = sales[0], max = sales[0], sum = 0.0;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < NUM_MONTHS; i++) {
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
    }

    float average = sum / NUM_MONTHS;

    printf("Minimum sales: $%.2f (%s)\n", min, months[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[maxMonth]);
    printf("Average sales: $%.2f\n", average);
}

// Function to print the Six-Month Moving Average Report
void printSixMonthMovingAverageReport(float sales[]) {
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s: $%.2f\n", 
               (i == 0) ? "January" : (i == 1) ? "February" : (i == 2) ? "March" : (i == 3) ? "April" : 
               (i == 4) ? "May" : (i == 5) ? "June" : (i == 6) ? "July" : (i == 7) ? "August" : (i == 8) ? "September" : "October",
               (i == 0) ? "June" : (i == 1) ? "July" : (i == 2) ? "August" : (i == 3) ? "September" : 
               (i == 4) ? "October" : (i == 5) ? "November" : (i == 6) ? "December" : "", 
               sum / 6);
    }
}

// Function to print the Sales Report (Highest to Lowest)
void printSalesReportHighestToLowest(float sales[], const char *months[]) {
    // Bubble sort to sort sales in descending order and align months
    float sortedSales[NUM_MONTHS];
    const char *sortedMonths[NUM_MONTHS];

    // Copy original sales and months to sorted arrays
    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Bubble sort
    for (int i = 0; i < NUM_MONTHS - 1; i++) {
        for (int j = 0; j < NUM_MONTHS - i - 1; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {
                // Swap sales
                float tempSales = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = tempSales;

                // Swap corresponding months
                const char *tempMonth = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonth;
            }
        }
    }

    // Print sorted sales report
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}
