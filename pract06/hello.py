def diagnose_covid_19():
    print("You might have COVID-19. Please get tested and consult a healthcare provider for further evaluation.")

def diagnose_flu():
    print("You might have the flu. Please rest, drink fluids, and consult a doctor if symptoms worsen.")

def diagnose_common_cold():
    print("You might have a common cold. Rest, drink fluids, and monitor your symptoms. Consult a doctor if it persists.")

def diagnose_viral_infection():
    print("This could be a viral infection. Please rest and hydrate, but consult a doctor if symptoms worsen.")

def diagnose_mild_fever():
    print("You might have a mild fever. Rest, hydrate, and monitor symptoms. If fever persists, consult a doctor.")

def diagnose_heart_attack():
    print("You might be experiencing a heart attack. Seek emergency medical attention immediately!")

def diagnose_angina():
    print("You may have angina. Please seek medical attention to evaluate your heart health.")

def diagnose_arrhythmia():
    print("You may be experiencing arrhythmia (irregular heartbeat). Please seek immediate medical attention.")

def diagnose_dehydration():
    print("You might be dehydrated. Drink fluids and rest. If symptoms persist, consult a doctor.")

def diagnose_gastroenteritis():
    print("You might have gastroenteritis (stomach flu). Stay hydrated, avoid heavy foods, and consult a doctor if symptoms worsen.")

def diagnose_acid_reflux():
    print("You may have acid reflux. Avoid spicy and acidic foods. If symptoms persist, see a gastroenterologist.")

def diagnose_diabetes():
    print("You might have diabetes. Please consult a healthcare provider for a blood sugar test.")

def diagnose_heartburn():
    print("You might be experiencing heartburn. Avoid heavy meals and acidic foods. Consult a doctor if symptoms persist.")

def hospital_expert_system():
    print("Welcome to the Hospital Expert System")
    print("Please answer the following questions with 'yes' or 'no'.\n")

    # Initial questions about fever and fatigue
    fever = input("Do you have a fever? (yes/no): ").lower()
    
    if fever == "yes":
        cough = input("Do you have a cough? (yes/no): ").lower()
        if cough == "yes":
            shortness_of_breath = input("Do you have shortness of breath? (yes/no): ").lower()
            if shortness_of_breath == "yes":
                diagnose_covid_19()
            else:
                fatigue = input("Do you feel unusually tired or fatigued? (yes/no): ").lower()
                if fatigue == "yes":
                    diagnose_flu()
                else:
                    headache = input("Do you have a headache? (yes/no): ").lower()
                    if headache == "yes":
                        diagnose_viral_infection()
                    else:
                        diagnose_mild_fever()
        else:
            headache = input("Do you have a headache? (yes/no): ").lower()
            if headache == "yes":
                diagnose_viral_infection()
            else:
                body_aches = input("Do you have body aches? (yes/no): ").lower()
                if body_aches == "yes":
                    diagnose_flu()
                else:
                    diagnose_mild_fever()
    else:
        chest_pain = input("Do you have chest pain? (yes/no): ").lower()
        if chest_pain == "yes":
            sweating = input("Do you have excessive sweating? (yes/no): ").lower()
            if sweating == "yes":
                nausea = input("Do you feel nauseous? (yes/no): ").lower()
                if nausea == "yes":
                    diagnose_heart_attack()
                else:
                    dizziness = input("Do you feel dizzy or lightheaded? (yes/no): ").lower()
                    if dizziness == "yes":
                        diagnose_angina()
                    else:
                        print("You should see a doctor for a full cardiac evaluation.")
            else:
                arrhythmia = input("Do you have irregular heartbeats or palpitations? (yes/no): ").lower()
                if arrhythmia == "yes":
                    diagnose_arrhythmia()
                else:
                    print("Chest pain could be related to several conditions. Please seek medical help for a thorough examination.")
        else:
            stomach_pain = input("Do you have stomach pain? (yes/no): ").lower()
            if stomach_pain == "yes":
                nausea = input("Do you feel nauseous? (yes/no): ").lower()
                if nausea == "yes":
                    vomiting = input("Do you have vomiting? (yes/no): ").lower()
                    if vomiting == "yes":
                        diagnose_gastroenteritis()
                    else:
                        heartburn = input("Do you have heartburn or acid reflux? (yes/no): ").lower()
                        if heartburn == "yes":
                            diagnose_acid_reflux()
                        else:
                            diagnose_dehydration()
                else:
                    bloating = input("Do you have bloating or gas? (yes/no): ").lower()
                    if bloating == "yes":
                        diagnose_acid_reflux()
                    else:
                        diagnose_dehydration()
            else:
                dizziness = input("Do you feel dizzy or lightheaded? (yes/no): ").lower()
                if dizziness == "yes":
                    weakness = input("Do you feel weak or faint? (yes/no): ").lower()
                    if weakness == "yes":
                        diagnose_dehydration()
                    else:
                        fainting = input("Do you have episodes of fainting or near-fainting? (yes/no): ").lower()
                        if fainting == "yes":
                            diagnose_diabetes()
                        else:
                            print("You might just be tired. Rest and monitor your symptoms.")
                else:
                    fatigue = input("Do you feel unusually fatigued? (yes/no): ").lower()
                    if fatigue == "yes":
                        print("You might have an underlying issue like diabetes or dehydration. Please consult a healthcare provider.")
                    else:
                        print("You seem to be healthy, but if you feel unwell, consider consulting a healthcare provider.")

# Call the expert system
hospital_expert_system()
