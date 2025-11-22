# 📊 WELBREXA

A console-based C++ application designed to help users reflect on their emotional and job-related well-being through daily tracking, scoring, and personalized recommendations.

---

## 📘 Problem Statement

In modern work environments, employees often struggle to balance professional demands with personal well-being. Stress, emotional fatigue, and diminishing motivation can harm both productivity and life satisfaction.

This project provides a simple interactive system that evaluates daily emotional and job-related factors—both positive and negative—and generates personalized recommendations to help users restore balance and improve overall well-being.

---

## 🎯 Purpose, Goals & Expected Outcomes

### **Purpose**
To help users become more aware of how their daily emotional and job-related experiences influence their overall well-being, while providing tailored suggestions to support a healthier work-life balance.

### **Goals**
1. Track and score daily positive and negative experiences.
2. Evaluate well-being trends across multiple days.
3. Generate personalized feedback and improvement suggestions.
4. Allow users to provide feedback on the system's accuracy.

### **Expected Outcomes**
- A functional C++ application for daily emotional/job-related analysis.
- A scoring-based evaluation model reflecting real-time well-being.
- Insightful recommendations that encourage work-life balance and personal development.

---

## 📝 Requirement Analysis

### **Inputs**
- Daily positive and negative factors selected or scored by the user.
- Numerical score for each factor (0–50).
- Optional self-feedback on evaluation accuracy.

### **Processes**
- Aggregation of daily emotional and job-related scores.
- Determination of daily emotional balance.
- Weekly trend analysis and pattern detection.
- Recommendation generation (e.g., rest, exercise, help others).
- Feedback loop to refine suggestions.

### **Outputs**
- Daily summary and emotional balance status.
- Balanced vs. imbalanced state indication.
- Weekly trend insights.
- Personalized task recommendations for improvement.

---

## 🔒 Constraints & Data Validation

- Scores must be within **0–50** per factor.
- Minimum of **3 days** of input required for meaningful pattern analysis.
- Duplicate factors cannot be selected on the same day.

