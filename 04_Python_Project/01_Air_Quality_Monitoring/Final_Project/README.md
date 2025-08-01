
# Real-Time Air Quality Monitoring Near Transport Corridors

This project monitors and predicts air quality near transport corridors using pollution data (PM2.5, NO₂, CO, O₃). It uses a machine learning model to estimate AQI (Air Quality Index) and displays the results on a web-based dashboard.

---

## Project Features

- Ingest pollution data from CSV files
- Clean the data and compute AQI using a simplified formula
- Train a Random Forest machine learning model to predict AQI from pollutant levels
- Visualize pollutant trends using Streamlit
- Display real-time alerts on the dashboard based on AQI health categories
- Organized, modular structure for scalability

---

## Folder Structure

Air_Quality_Monitoring/Final_Project/
├── Data/
│ └── delhi_aqi.csv # Raw dataset
│ └── cleaned_data.csv # Preprocessed data with AQI (auto-generated)
├── Code/
│ ├── data_processing.py # Cleans data and computes AQI
│ ├── training_model.py # Trains ML model
│ ├── data_visualization.py # Plots pollutant trends and correlation
│ └── app.py # Streamlit web dashboard
├── requirements.txt
└── README.md

---

## Setup Instructions

1. Clone the repository or download the folder.
2. Install required dependencies using the command below:
Open Command Prompt 
pip install -r requirements.txt

---

## Execution Steps

1. cd <project_code_path>
2. project.bat

---