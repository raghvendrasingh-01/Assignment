#include <stdio.h>

double calculate_old_regime(double income) {
    double tax = 0;
    double taxable = income - 50000; // Standard deduction
    
    if (taxable <= 250000) {
        tax = 0;
    } else if (taxable <= 500000) {
        tax = (taxable - 250000) * 0.05;
    } else if (taxable <= 1000000) {
        tax = 12500 + (taxable - 500000) * 0.20;
    } else {
        tax = 112500 + (taxable - 1000000) * 0.30;
    }
    
    // Rebate under Section 87A
    if (taxable <= 500000) {
        tax = 0;
    }
    
    return tax;
}

double calculate_new_regime(double income) {
    double tax = 0;
    double taxable = income - 75000; // Standard deduction
    
    if (taxable <= 400000) {
        tax = 0;
    } else if (taxable <= 800000) {
        tax = (taxable - 400000) * 0.05;
    } else if (taxable <= 1200000) {
        tax = 20000 + (taxable - 800000) * 0.10;
    } else if (taxable <= 1600000) {
        tax = 60000 + (taxable - 1200000) * 0.15;
    } else if (taxable <= 2000000) {
        tax = 120000 + (taxable - 1600000) * 0.20;
    } else if (taxable <= 2400000) {
        tax = 200000 + (taxable - 2000000) * 0.25;
    } else {
        tax = 300000 + (taxable - 2400000) * 0.30;
    }
    
    // Rebate under Section 87A
    if (taxable <= 1200000) {
        tax = 0;
    }
    
    return tax;
}

double calculate_cess(double tax) {
    return tax * 0.04; // 4% Health and Education Cess 
}

int main() {
    double income;
    int regime;
    
    printf("=====================================\n");
    printf("   Income Tax Calculator FY 25-26   \n");
    printf("=====================================\n\n");
    
    printf("Enter your annual income (Rs): ");
    scanf("%lf", &income);
    
    printf("\nSelect Tax Regime:\n");
    printf("1. Old Regime\n");
    printf("2. New Regime\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &regime);
    
    double tax = 0;
    double cess = 0;
    double total_tax = 0;
    
    printf("\n=====================================\n");
    printf("        Tax Calculation Summary      \n");
    printf("=====================================\n\n");
    
    if (regime == 1) {
        printf("Regime: OLD REGIME\n");
        printf("Standard Deduction: Rs. 50,000\n");
        printf("Taxable Income: Rs. %.2lf\n\n", income - 50000);
        
        tax = calculate_old_regime(income);
        cess = calculate_cess(tax);
        total_tax = tax + cess;
        
        printf("Income Tax: Rs. %.2lf\n", tax);
        printf("Health & Education Cess (4%%): Rs. %.2lf\n", cess);
        printf("-------------------------------------\n");
        printf("Total Tax Liability: Rs. %.2lf\n", total_tax);
        
        if (income - 50000 <= 500000) {
            printf("\n* You are eligible for tax rebate under Section 87A\n");
            printf("* Income up to Rs. 5.5 Lakhs - 0 Tax\n");
        }
    } 
    else if (regime == 2) {
        printf("Regime: NEW REGIME\n");
        printf("Standard Deduction: Rs. 75,000\n");
        printf("Taxable Income: Rs. %.2lf\n\n", income - 75000);
        
        tax = calculate_new_regime(income);
        cess = calculate_cess(tax);
        total_tax = tax + cess;
        
        printf("Income Tax: Rs. %.2lf\n", tax);
        printf("Health & Education Cess (4%%): Rs. %.2lf\n", cess);
        printf("-------------------------------------\n");
        printf("Total Tax Liability: Rs. %.2lf\n", total_tax);
        
        if (income - 75000 <= 1200000) {
            printf("\n* You are eligible for tax rebate under Section 87A\n");
            printf("* Income up to Rs. 12.75 Lakhs - 0 Tax\n");
        }
    } 
    else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    printf("\n=====================================\n");
    printf("Note: Calculations exclude surcharge\n");
    printf("=====================================\n");
    
    return 0;
}