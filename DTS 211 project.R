# 1. Data Import and Exploration
iris
head(iris)
summary(iris)
# 2. Data Visualization
library(ggplot2)
ggplot(iris, aes(x=Sepal.Length, y=Sepal.Width, alpha=Species)) + 
  geom_point(size=6, color="orange") +
  ggtitle("Relationship Between Sepal length an Sepal Width") 
library(ggplot2)
ggplot(iris, aes(x=Petal.Length, y=Petal.Width, alpha=Species)) + 
  geom_point(size=6, color="Blue") +
  ggtitle("Relationship Between Petal length an Petal Width") 
boxplot(Sepal.Length ~ Species, data = iris, main = "Sepal Length by Species", ylab = "Sepal Length")
boxplot(Sepal.Width ~ Species, data = iris, main = "Sepal Length by Species", ylab = "Sepal Width")
boxplot(Petal.Length ~ Species, data = iris, main = "Sepal Length by Species", ylab = "Petal Length")
boxplot(Petal.Width ~ Species, data = iris, main = "Sepal Length by Species", ylab = "Petal Width")
hist(iris$Sepal.Length, main = "Histogram of Sepal Length", xlab = "Sepal Length", col = "lightblue")
hist(iris$Sepal.Width, main = "Histogram of Sepal Width", xlab = "Sepal Width", col = "lightblue")
hist(iris$Petal.Length, main = "Histogram of Petal Length", xlab = "Petal Length", col = "lightblue")
hist(iris$Petal.Width, main = "Histogram of Petal Width", xlab = "Petal Width", col = "lightblue")
library(ggplot2)
ggplot(iris, aes(x = Sepal.Length, fill = Species)) + 
  geom_density(alpha = 0.5) + 
  labs(title = "Density Plot of Sepal Length by Species")
library(ggplot2)
ggplot(iris, aes(x = Sepal.Width, fill = Species)) + 
  geom_density(alpha = 0.5) + 
  labs(title = "Density Plot of Sepal Width by Species")
library(ggplot2)
ggplot(iris, aes(x = Petal.Length, fill = Species)) + 
  geom_density(alpha = 0.5) + 
  labs(title = "Density Plot of Petal Length by Species")
library(ggplot2)
ggplot(iris, aes(x = Petal.Width, fill = Species)) + 
  geom_density(alpha = 0.5) + 
  labs(title = "Density Plot of Petal Width by Species")
#3. Statistical Summary and Insights
mean(iris$Sepal.Length)
median(iris$Sepal.Length)
sd(iris$Sepal.Length)
mean(iris$Sepal.Width)
median(iris$Sepal.Width)
sd(iris$Sepal.Width)
mean(iris$Petal.Length)
median(iris$Petal.Length)
sd(iris$Petal.Length)
mean(iris$Petal.Width)
median(iris$Petal.Width)
sd(iris$Petal.Width)
#4  Simple Classification Model
#Split the Dataset:
set.seed(123)
index <- sample(1:nrow(iris), 0.7 * nrow(iris))
train_data <- iris[index, ]
test_data <- iris[-index, ]
# Implement k-Nearest Neighbors (k-NN):
library(class)
k <- 3  # Choose k value (can be tuned)
predicted_species <- knn(train = train_data[, 1:4], test = test_data[, 1:4], cl = train_data$Species, k = k)
#Evaluate Model Performance
table(predicted_species, test_data$Species)
#Confusion Matrix
accuracy <- sum(predicted_species == test_data$Species) / nrow(test_data)
print(paste("Accuracy:", round(accuracy * 100, 2), "%"))

