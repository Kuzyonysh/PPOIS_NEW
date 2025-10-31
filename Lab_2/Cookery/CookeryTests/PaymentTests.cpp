#include "gtest/gtest.h"
#include "D:\Projects\Cookery\Cookery\Payment.h"
#include "D:\Projects\Cookery\Cookery\PaymentManager.h"
#include "D:\Projects\Cookery\Cookery\ConsolePaymentPrinter.h"
#include <sstream>
#include <iostream>

using namespace std;


TEST(PaymentTest, ConstructorSetsInitialValues) {
    Payment payment(100.0, "Card");

    EXPECT_EQ(payment.getAmount(), 100.0);
    EXPECT_EQ(payment.getMethod(), "Card");
    EXPECT_FALSE(payment.isPaid());
    EXPECT_EQ(payment.getCurrency(), "BYN");
    EXPECT_EQ(payment.getTransactionId(), "");
    EXPECT_EQ(payment.getPayerName(), "");
    EXPECT_EQ(payment.getRecipientName(), "");
    EXPECT_EQ(payment.getPaymentDate(), "");
    EXPECT_EQ(payment.getNotes(), "");
    EXPECT_FALSE(payment.getIsRecurring());
}

TEST(PaymentTest, SettersWorkCorrectly) {
    Payment payment(50, "Cash");
    payment.setAmount(75);
    payment.setMethod("Card");
    payment.setCurrency("USD");
    payment.setTransactionId("TX123");
    payment.setPayerName("Alice");
    payment.setRecipientName("Bob");
    payment.setPaymentDate("2025-10-30");
    payment.setNotes("Test payment");
    payment.setRecurring(true);

    EXPECT_EQ(payment.getAmount(), 75);
    EXPECT_EQ(payment.getMethod(), "Card");
    EXPECT_EQ(payment.getCurrency(), "USD");
    EXPECT_EQ(payment.getTransactionId(), "TX123");
    EXPECT_EQ(payment.getPayerName(), "Alice");
    EXPECT_EQ(payment.getRecipientName(), "Bob");
    EXPECT_EQ(payment.getPaymentDate(), "2025-10-30");
    EXPECT_EQ(payment.getNotes(), "Test payment");
    EXPECT_TRUE(payment.getIsRecurring());
}

TEST(PaymentTest, PayChangesStatus) {
    Payment payment(100, "Card");
    EXPECT_FALSE(payment.isPaid());
    payment.pay();
    EXPECT_TRUE(payment.isPaid());
}

TEST(PaymentTest, RefundChangesStatus) {
    Payment payment(100, "Card", true);
    EXPECT_TRUE(payment.isPaid());
    payment.refund();
    EXPECT_FALSE(payment.isPaid());
}

TEST(PaymentTest, PayWhenAlreadyPaidDoesNotChange) {
    Payment payment(100, "Card", true);
    payment.pay();
    EXPECT_TRUE(payment.isPaid());
}

TEST(PaymentTest, RefundWhenNotPaidDoesNotChange) {
    Payment payment(100, "Card", false);
    payment.refund();
    EXPECT_FALSE(payment.isPaid());
}


TEST(PaymentManagerTest, MakePaymentChangesStatus) {
    Payment payment(200, "Card", false);
    PaymentManager manager;
    manager.makePayment(payment);
    EXPECT_TRUE(payment.isPaid());
}

TEST(PaymentManagerTest, MakePaymentAlreadyPaidOutputsMessage) {
    Payment payment(100, "Cash", true);
    PaymentManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.makePayment(payment);
    cout.rdbuf(oldCout);

    EXPECT_NE(buffer.str().find("Already paid"), string::npos);
}

TEST(PaymentManagerTest, IssueRefundChangesStatus) {
    Payment payment(150, "Card", true);
    PaymentManager manager;
    manager.issueRefund(payment);
    EXPECT_FALSE(payment.isPaid());
}

TEST(PaymentManagerTest, IssueRefundNotPaidOutputsMessage) {
    Payment payment(150, "Cash", false);
    PaymentManager manager;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    manager.issueRefund(payment);
    cout.rdbuf(oldCout);

    EXPECT_NE(buffer.str().find("Payment is not made yet"), string::npos);
}


TEST(ConsolePaymentPrinterTest, PrintOutputsCorrectTextPaid) {
    Payment payment(120, "Card", true);
    ConsolePaymentPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    printer.print(payment);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Payment information"), string::npos);
    EXPECT_NE(output.find("Amount: 120"), string::npos);
    EXPECT_NE(output.find("Method: Card"), string::npos);
    EXPECT_NE(output.find("Status: Paid"), string::npos);
}

TEST(ConsolePaymentPrinterTest, PrintOutputsCorrectTextNotPaid) {
    Payment payment(75, "Cash", false);
    ConsolePaymentPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    printer.print(payment);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Status: Not paid"), string::npos);
}

TEST(ConsolePaymentPrinterTest, ShowPaymentInfoCallsPrint) {
    Payment payment(50, "Card", false);
    ConsolePaymentPrinter printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());
    printer.showPaymentInfo(payment);
    cout.rdbuf(oldCout);

    string output = buffer.str();
    EXPECT_NE(output.find("Amount: 50"), string::npos);
    EXPECT_NE(output.find("Method: Card"), string::npos);
}


TEST(PaymentTest, MultiplePayAndRefund) {
    Payment payment(300, "Card");
    EXPECT_FALSE(payment.isPaid());

    payment.pay();
    EXPECT_TRUE(payment.isPaid());

    payment.refund();
    EXPECT_FALSE(payment.isPaid());

    payment.pay();
    EXPECT_TRUE(payment.isPaid());
}

TEST(PaymentManagerTest, MakePaymentAndRefundSequence) {
    Payment payment(500, "Cash");
    PaymentManager manager;

    manager.makePayment(payment);
    EXPECT_TRUE(payment.isPaid());

    manager.issueRefund(payment);
    EXPECT_FALSE(payment.isPaid());
}
