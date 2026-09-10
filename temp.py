import time
import requests
from bs4 import BeautifulSoup

URL = "https://gradecard.ignou.ac.in/mpddstatus/Jan26/StudentMaterialStatus.aspx"

session = requests.Session()

session.headers.update({
    "User-Agent": "Mozilla/5.0",
    "Referer": URL,
    "Origin": "https://gradecard.ignou.ac.in",
})

def get_tokens():
    r = session.get(URL, timeout=30)
    r.raise_for_status()

    soup = BeautifulSoup(r.text, "html.parser")

    return {
        "__VIEWSTATE": soup.select_one("#__VIEWSTATE")["value"],
        "__VIEWSTATEGENERATOR": soup.select_one("#__VIEWSTATEGENERATOR")["value"],
        "__EVENTVALIDATION": soup.select_one("#__EVENTVALIDATION")["value"],
    }

def submit_enrollment(enrollment):
    tokens = get_tokens()

    payload = {
        "__VIEWSTATE": tokens["__VIEWSTATE"],
        "__VIEWSTATEGENERATOR": tokens["__VIEWSTATEGENERATOR"],
        "__EVENTVALIDATION": tokens["__EVENTVALIDATION"],
        "EnrNo": enrollment,
        "SubmitStage1": "Submit",
    }

    r = session.post(URL, data=payload, timeout=30)
    r.raise_for_status()

    return r.text

# Example: checking known enrollment numbers
enrollments = [
    "2612345678",
    "2612345679",
    "2612345680",
]

for enr in enrollments:
    print("Checking", enr)

    html = submit_enrollment(enr)

    if "Enrollment No. Not found..." not in html:
        print("FOUND:", enr)

        with open(f"{enr}.html", "w", encoding="utf-8") as f:
            f.write(html)

        break

    time.sleep(1)