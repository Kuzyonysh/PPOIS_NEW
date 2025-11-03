# README: Предметная область Кулинария (Cookery)

- Классы: 64
- Поля: 215
- Уникальные поведения: 105
- Ассоциации: 42
- Исключения: 13

## Исключения (13)

Все исключения наследуются от базового класса `CookingException` и предназначены для обработки ошибок, связанных с готовкой, ингредиентами, печью и рабочими местами.  

- `InvalidIngredientAmountException("сообщение")` — недопустимое количество ингредиента.  
- `DuplicateIngredientException("сообщение")` — дубликат ингредиента.  
- `DuplicateDishException("сообщение")` — дубликат блюда.  
- `DishNotFoundException("сообщение")` — блюдо не найдено.  
- `InvalidTemperatureException("сообщение")` — недопустимая температура для печи.  
- `InvalidTimeException("сообщение")` — недопустимое время приготовления.  
- `OvenException("сообщение")` — ошибка печи.  
- `InvalidModeException("сообщение")` — недопустимый режим печи.  
- `InvalidDiameterException("сообщение")` — недопустимый диаметр посуды/кастрюли.  
- `DuplicateWorkplaceException("сообщение")` — дублирование рабочего места.  
- `NotEnoughTemperatureException("сообщение")` — недостаточная температура для приготовления.  
- `FridgeOverflowException("сообщение")` — холодильник переполнен, нельзя добавить новый продукт.  

## Классы
Формат: Класс Поля Методы → Ассоциации (классы как поля/параметры)

Category 6 12 → ICategory
- Поля:  name, description, cuisineType, popularityLevel, vegetarian, recommendedDishCount
- Методы: getName, getDescription, setDescription, matches, getCuisineType, setCuisineType, getPopularityLevel, setPopularityLevel, isVegetarian, setVegetarian, getRecommendedDishCount, setRecommendedDishCount  

ConsoleCategoryPrinter 0 1 → ICategory
- Методы: print
  
Cook 8 17 → ICook, Dish
- Поля: name, skillLevel, dishes, experienceYears, specialty, age, awards, isAvailble
- Методы: getName, getSkillLevel, getDishes, getExperienceYears, getSpecialty, getAge, getAwards, getIsAvailable, setName, setSkillLevel, setDishes, addDish, setExperienceYears, setSpecialty, setAge, setAwards, setIsAvailable 

CookManager 0 4 → Cook,Dish
- Методы: cookDish, canCook, addDish, improveSkill
  
ConsoleCookPrinter 0 1 → ICook
- Методы: print
  
Customer 7 13 → ICustomer, Dish
- Поля: name, orders, preferences, email, phone, loyaltyPoints, vipStatus
- Методы: getName, getOrders, getPreferences, getEmail, getPhone, getLoyaltyPoints, isVIP, addOrder, setPreference, setEmail, setPhone, addLoyaltyPoints, setVIP

MakeOrder 0 1 → ICustomer, Dish
- Методы: makeOrder

ConsoleCustomerPrinter 0 1 → ICustomer
- Методы: print  
  
Delivery 5 6 → IDelivery
- Поля: distance, weight, baseRate, speed, status
- Методы: getDistance, getWeight, getBaseRate, getSpeed, getStatus, setStatus

DeliveryCalculator 0 7 → IDelivery
- Методы: calculateTime, calculateCost, estimateDelay, isPriority, calculateCostWithWeight, canDeliver, averageDeliveryTime
  
ConsoleDeliveryPrinter 1 2 → IDelivery, deliveryCalculator
- Поля: calculator
- Методы: print, printAll
  
Dish 8 14 → Category, IDish
- Поля: name, calories, category, description, price, spicyLevel, isVegetarian, preparationTime
- Методы: getName, getCalories, getCategoryName, getDescription, getPrice, getSpicyLevel, getIsVegetarian, getPreparationTime, setCalories, setDescription, setPrice, setSpicyLevel, setIsVegetarian, setPreparationTime

DishManager 0 3 → IDish
- Методы: addDish, removeDish, findDish

ConsoleDishPrinter 0 1 → IDish
- Методы: print  

Fridge 4 6 → IFridge, Inventory
- Поля: temperature, state, maxCapacity, inventory
- Методы: getTemperature, getState, getMaxCapacity, getInventory, setTemperature, setState

FridgeManager 2 3 → IFridge, Ingredient, ITemperatureSensor
- Поля: sensor, maxSafeTemp
- Методы: turnOnOff, setTemperature, addIngredient

ConsoleFridgePrinter 0 1 → IFridge
- Методы: print  

Ingredient 9 16 
- Поля: name, quantity, unit, supplier, expirationDate, storageLocation, pricePerUnit, category, organic
- Методы: getName, getQuantity, getUnit, setQuantity, setSupplier, setExpirationDate, setStorageLocation, setPricePerUnit, setCategory, setOrganic, getSupplier, getExpirationDate, getStorageLocation, getPricePerUnit, getCategory, isOrganic

IngredientManager 1 2 → Ingredient
- Поля: ingredient
- Методы: decrease, refill 

ConsoleIngredientPrinter 0 1 → Ingredient
- Методы: print  

Inventory 6 8 → Ingredient, IInventory
- Поля: ingredients, capacity, name, location, owner, lastUpdated
- Методы: addIngredient, size, getCapacity, getIngredients, getName, getLocation, getOwner, getLastUpdated

InventoryManager 1 5 → IInventory
- Поля: inventory
- Методы: add, isFull, freeSpace, hasIngredient, clearInventory 

InventoryPrinter 0 1 → IInventory
- Методы: print  

ConsoleKitchenPrinter 0 1 → Kitchen
- Методы: print  

Kitchen 4 9 → IKitchen, Tool
- Поля: name, capacity, tools, workplace
- Методы: getTools, getWorkplaces, getName, getCapacity, addTool, addWorkplace, setName, setCapacity, isReady

KitchenManager 0 7 → IKitchen
- Методы: addWorkplace, addTool, renameKitchen, changeCapacity, listTools, listWorkplaces, checkReady

Menu 4 10 → Dish
- Поля: dishes, name, description, averagePrice
- Методы: getDishes, getName, getDescription, getAveragePrice, setName, setDescription, setAveragePrice, addDish, getByCategory, hasDish

ConsoleMenuPrinter 0 1 → Menu
- Методы: print  

Order 7 13 → IOrder, Dish, Customer
- Поля: client, dishes, orderTime, status, deliveryAddress, paymentMethod, comment
- Методы: getStatus, getOrderTime, getClient, getDishes, getDeliveryAddress, getPaymentMethod, getComment, setStatus, addOrder, setDeliveryAddress, setPaymentMethod, setComment, isReadyToServe

OrderManager 0 7 → IOrder
- Методы: getTotalCalories, markAsServed, addDishToOrder, cancelOrder, updateDeliveryAddress, updatePaymentMethod, addComment

ConsoleOrderPrinter 0 1 → IOrder
- Методы: print  

Oven 15 28 → Dish
- Поля: temperature, mode, cookingTime, isOn, isDoorClosed, brand, power, color, material, capacity, width, height, depth, hasTimer, hasLight
- Методы: getTemperature, getMode, getCookingTime, getPowerState, getDoorState, getBrand, getPower, getColor, getMaterial, getCapacity, getWidth, getHeight, getDepth, hasTimerFunction, hasLightFunction, setTemperature, setMode, setCookingTime, setDoorState, setPowerState, setColor, setMaterial, setCapacity, setWidth, setHeight, setDepth, setTimerFunction, setLightFunction

OrderManager 0 8 → Oven
- Методы: startCooking, stopCooking, openDoor, closeDoor, clean, preheat, resetSettings, testHeating

ConsoleOrderPrinter 0 1 → Oven
- Методы: print
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  
Pan 8 16 → IPan
- Поля: material, diameter, state, depth, hasLid, temperature, weight, brand
- Методы: getMaterial, getDiameter, getState, getDepth, getHasLid, getTemperature, getWeight, getBrand, setMaterial, setDiameter, setState, setDepth, setHasLid, setTemperature, setWeight, setBrand
  
PanHeatingManager 0 3 → IPan
- Методы: heatUp, coolDown, checkReady

PanCareManager 0 2 → IPan, Pan
- Методы: clean, inspect

PanStorageManager 0 3 → Pan
- Методы: cover, replaceLid, store

ConsolePanPrinter 0 1 → Pan
- Методы: print

Payment 10 21 → IPayment
- Поля: amount, method, paid, currency, transactionId, payerName, recipientName, paymentDate, notes, isRecurring
- Методы: pay, refund, getAmount, getMethod, isPaid, getCurrency, getTransactionId, getPayerName, getRecipientName, getPaymentDate, getNotes, getIsRecurring, setAmount, setMethod, setCurrency, setTransactionId, setPayerName, setRecipientName, setPaymentDate, setNotes, setRecurring

PaymentManager 0 2 → IPayment
- Методы: makePayment, issueRefund

ConsolePaymentPrinter 0 2 → Pan
- Методы: print, showPaymentInfo

Recipe 10 17 → IRecipe, Ingredient
- Поля: name, ingredients, instruction, cookingTime, cuisineType, difficultyLevel, servings, chefName, notes, isVegetarian
- Методы: getName, getCookingTime, getIngredients, getInstruction, getCuisineType, getDifficultyLevel, getServings, getChefName, getNotes, getIsVegetarian, setCuisineType, setDifficultyLevel, setServings, setChefName, setNotes, setVegetarian, addIngredientInternal

RecipeManager 0 4 → IRecipe, Recipe
- Методы: addIngredient, cook, removeRecipe, findRecipe

ConsoleRecipePrinter 0 1 → Recipe
- Методы: print

Reservation 12 21 → IReservation, Customer
- Поля: customer, date, tableNumber, confirmed, specialRequest, numberOfGuests, occasion, notes, depositAmount, contactPhone, email, vip
- Методы: getCustomer, getDate, getTableNumber, isConfirmed, setConfirmed, setSpecialRequest, setNumberOfGuests, getSpecialRequest, getNumberOfGuests, setOccasion, setNotes, setDepositAmount, setContactPhone, setEmail, setVIP, getOccasion, getNotes, getDepositAmount, getContactPhone, getEmail, isVIP

ReservationManager 0 2 → IReservation
- Методы: confirm, cancel

Review 9 6 → IReview
- Поля: author, comment, rating, title, productName, date, reviewerEmail, likes, dislikes
- Методы: getAuthor, getComment, getRating, setAuthor, setComment, setRating

ReviewManager 0 2 → IReview, Review
- Методы: addReview, isPositive

Step 2 2 → IStep
- Поля: action, time
- Методы: getAction, getTime

RecipeSteps 1 3 → IStep
- Поля: steps
- Методы: addStep, getSteps, getTotalTime

ConsolePrinterStep 0 2 → Recipe, RecipeSteps
- Методы: print, print

TemperatureSensor 5 8 → ITemperatureSensor
- Поля: currentTemperature, maxSafeTemperature, minSafeTemperature, sensorLocation, sensorType
- Методы: setCurrentTemperature, getCurrentTemperature, getMinSafe, getMaxSafe, setSensorLocation, getSensorLocation, setSensorType, getSensorType

TemperatureController 1 3 → ITemperatureSensor
- Поля: sensor
- Методы: measure, checkSafety, calibrate

ConsolePrinterTemperatureSensor 0 1 → ITemperatureSensor
- Методы: print

Timer 4 9 → ITimer
- Поля: elapsedTime, isRunning, limit, name
- Методы: setRunning, running, setElapsedTime, getElapsedTime, setLimit, getLimit, setName, getName, isOverLimit

TimerController 1 7 → ITimer
- Поля: timer
- Методы: start, pause, stop, addMinutes, reset, fastForward, checkStatus

ConsoleTimerPrinter 0 1 → Timer
- Методы: print

Tool 10 18 → ITool
- Поля: name, condition, purpose, material, weight, brand, color, durability, length, width
- Методы: getName, getConditionName, getPurposeName, getMaterial, getWeight, getBrand, getColor, getDurability, getLength, getWidth, setCondition, setMaterial, setWeight, setBrand, setColor, setDurability, setLength, setWidth

ToolManager 0 3 → ITool
- Методы: use, repair, breakTool

ConsoleToolPrinter 0 1 → Tool
- Методы: print


