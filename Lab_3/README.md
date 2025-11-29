# README: Приложение для отслеживания фитнеса (FitnessTracker)

- Классы: 51
- Поля: 153
- Уникальные поведения: 107
- Ассоциации: 50
- Исключения: 12

## Исключения (12)

Все исключения наследуются от базового класса `Exception` и предназначены для обработки ошибок.  

- `NoActivityDataException("сообщение")` — отсутствуют данные о физической активности для анализа. 
- `MembershipException("сообщение")` — ошибка, связанная с членством пользователя. 
- `WorkoutException("сообщение")` — ошибка при обработке тренировок.  
- `AppointmentException("сообщение")` — ошибка при работе с записями на приём.  
- `GoalException("сообщение")` — ошибка, связанная с целями пользователя.
- `MedicationException("сообщение")` — ошибка при обработке информации о лекарствах.  
- `MentalHealthException("сообщение")` — ошибка, связанная с ментальным здоровьем.  
- `InvalidBodyMetricsException("сообщение")` — недопустимые значения параметров тела.
- `EmptyDataAboutDream("сообщение")` — отсутствуют данные о сне. 
- `InvalidWaterAmountException("сообщение")` — некорректное количество воды.
- `InvalidHeightWeightException("сообщение")` — недопустимые значения роста или веса.  
- `InvalidIngredientAmountException("сообщение")` — недопустимое количество продуктов

## Классы
Формат: Класс Поля Уникальные поведения → Ассоциации (классы как поля/параметры)

User 7 0 → IUser
- Поля:  name, age, weight, height, gender, BMI, activity

UserManager 2 7 → IUser, BodyMetricsManager
- Поля: user, metricsMgr
- Методы: getCurrentBMI, getBMR, getActivityMultiplier, getTDEE, isHealthyWeightRange, getIdealWeightRange, printBMIStatus

 PrinterUser 0 1 → IUser
- Методы: print

FitnessTracker 9 0 → IFitnessTracker
- Поля: activityType, activityDate, activityDuration, activityCalories, types, dates, durations, calories, totalCaloriesBurned
  
FitnessTrackerService 3 5 → IFitnessTracker, IUser, UserManager
- Поля: tracker, user, manager
- Методы: getAverageCaloriesBurned, getTotalDuration, getMostCalorieBurningActivity, getAverageDuration, getCaloriesPerMinute

 PrinterFitnessTracker 0 1 → IFitnessTracker
- Методы: print
  
FoodProduct 8 0 
- Поля: name, quantity, unit, caloriesPerUnit, protein, fat, carbs, healthy
  
FoodProductManager 1 6 → FoodProduct
- Поля: product
- Методы: consume, isLowStock, calculateTotalCalories, getCaloriesForAmount, estimateDaysLeft, refill

FoodPrinter 0 1 → FoodProduct
- Методы: print

MealRecord 4 0 → FoodProduct, INutrition
- Поля: calories, date, mealType, products

MealRecordManager 1 9 → MealRecord
- Поля: records
- Методы: addMealRecord, removeMealRecord, findByDate, getTotalCaloriesByDate, getAllRecords, MealSkipped, MealPlanned, MealConsumed, CaloriesGoalReached

PrinterMeal 1 1 → INutrition, MealRecordManager
- Поля: manager
- Методы: print

 WaterIntake 4 0 
- Поля: date, amount, dailyGoal, note

WaterIntakeManager 1 5 → WaterIntake
- Поля: intake
- Методы: addWater, checkNorm, printProgress, remindToDrink, resetAmount

PrinterMeal 1 1 → WaterIntake, WaterIntakeManager
- Поля: manager
- Методы: print

SleepRecord 3 0
- Поля: date, hours, quality

SleepManager 1 7 → SleepRecord
- Поля: records
- Методы: addSleepRecord, getAverageQuality, getSleepHoursByDate, checkSleepQuality, exportSleepReport, sendSleepReminder, showSleepTrends

PrinterSleep 1 1 → SleepRecord
- Поля: manager
- Методы: print

BodyMetrics 5 0
- Поля: date, weight, height, waist, hips

BodyMetricsManager 1 8 → BodyMetrics
- Поля: records
- Методы: addMetrics, getLatestMetrics, getBMI, showAllRecords, printLatestWeight, printLatestHeight, notifyBMIStatus, resetRecords

PrinterBodyMetrics 1 1 → BodyMetrics, BodyMetricsManager
- Поля: manager
- Методы: print

BodyMetricsManager 1 8 → BodyMetrics
- Поля: records
- Методы: addMetrics, getLatestMetrics, getBMI, showAllRecords, printLatestWeight, printLatestHeight, notifyBMIStatus, resetRecords
 
PrinterDailyPlan 1 1 → DailyPlan, DailyPlanManager
- Поля: manager
- Методы: print

DailyPlan 5 0 → FitnessTracker, MealRecord, WaterIntake, SleepRecord
- Поля: date, meals, water, workouts, sleep

 DailyPlanManager 1 10 → DailyPlan
- Поля: plans
- Методы: addDailyPlan, getTotalCalories, getTotalWorkoutCalories, getTotalWater, checkDailyProgress, resetDailyPlans, showWorkouts, showMeals, showWaterIntake, showSleep

MoodRecord 4 0
- Поля: date, mood, stressLevel, note
  
MentalHealthManager 1 1 → MoodRecord
- Поля: records
- Методы: addMoodRecord, getAverageMood, getAverageStress, getMoodByDate

PrinterMentalHealth 1 1 → MoodRecord, MentalHealthMenager
- Поля: manager
- Методы: print  
 
 Medication 6 0 
- Поля: name, dose, frequency, startDate, endDate, note 
 
 MedicationMenager 1 3 → Medication
- Поля: meds
- Методы: addMedication, removeMedication, getAllMedications
 
PrinterMedication 1 2 → Medication, MedicationMenager
- Поля: manager
- Методы: print , printAll 
 
Appointment 6 0 
- Поля: date, time, doctor, location, reason, attended

 AppointmentManager 1 7 → Appointment
- Поля: appointments
- Методы: addAppointment, getAppointmentsByDoctor, cancelAppointment, getAppointment, getTotalAppointments, getAppointmentsByDate, markAppointmentAttended

PrinterAppointment 1 1 → Appointment, AppointmentManager
- Поля: manager
- Методы: print 
 
Goal 5 0 
- Поля: name, targetValue, currentValue, unit, achieved

GoalManager 1 9 → Goal
- Поля: goals
- Методы: addGoal, getAchievedGoals, getPendingGoals, markGoalAchieved, removeGoal, printAllGoals, totalGoals, achievedCount, pendingCount

PrinterGoal 0 1 → Goal
- Методы: print 

WorkoutSession 12 0 
- Поля: type, date, intensity, duration, caloriesBurned, location, trainerName, notes, avgHeartRate, steps, distance, completed

PrinterWorkout 0 1 → WorkoutSession
- Методы: print

HealthReport 16 0 
- Поля: date, avgSleepHours, avgSleepQuality, totalCaloriesConsumed, totalCaloriesBurned, calorieBalance, totalWaterIntake, waterGoal, avgMoodLevel, dominantEmotion, currentWeight, bmi, waist, hips, generalComment, healthImproved

HealthReportManager 7 2 → SleepManager, HealthReport, MealRecordManager, WaterIntake, BodyMetricsManager, MentalHealthManager, FitnessTracker
- Поля: reports, sleepManager, mealManager, water, bodyManager, mentalManager, fitnessTracker
- Методы: generateDailyReport, getAllReports

PrinterHealthReport 0 1 → HealthReport
- Методы: print

Membership 7 0 
- Поля: memberName, type, price, startDate, endDate, isActive, isPaid

MembershipManager 1 4 → Membership
- Поля: membership
- Методы: addMembership, getActiveCount, findByType,  getAll

PrinterMembership 0 1 → Membership
- Методы: print

Trainer 10 0 → ITrainer
- Поля: name, specialization, experienceYears, salary, isAvailable, contactInfo, age, rating, clientsCount, gender

TrainerManager 1 3 → ITrainer
- Поля: trainers
- Методы: getAvailableCount, getAll, addTrainer

PrinterTrainer 0 1 → ITrainer
- Методы: print

Challenge 7 0
- Поля: name, description, target, progress, startDate, endDate, completed

PrinterChallenge 0 1 → Challenge
- Методы: print

Equipment 3 0 
- Поля: name, type, isAvailable

PrinterEquipment 0 1 → Equipment
- Методы: print
  
**Примечание:** Есть 1 шаблонный абстрактный класс Printer, 4 интерфейса
