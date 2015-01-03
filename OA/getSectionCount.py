import requests
r = requests.get('https://api.clever.com/v1.1/sections', headers={'Authorization':'Bearer DEMO_TOKEN'})
m_data = r.json().get('data') 
m_count = {}
each_info = {}
for each_data in m_data:
    each_info = each_data.get('data')
    if each_info.get('course_name') not in m_count:
        m_count[each_info.get('course_name')] = 0
    m_count[each_info.get('course_name')] = m_count[each_info.get('course_name')]+len(each_info.get('students'))

sum = 0
count = 0
for key in m_count:
    count += 1
    sum += m_count[key]
    print(key, m_count[key]) 

print(sum/count)

"""
s = {
  "data":[
    {
      "data": {
        "course_name": "Group Guidance",
        "course_number": "101",
        "created": "2014-02-26T21:15:37.927Z",
        "district": "4fd43cc56d11340000000005",
        "grade": "10",
        "last_modified": "2014-12-29T15:49:36.680Z",
        "name": "Group Guidance - 101 - B. Greene (Section 1)",
        "period": "0",
        "school": "530e595026403103360ff9fd",
        "sis_id": "581",
        "students": [
          "530e5960049e75a9262cff4f",
          "530e5960049e75a9262cff95",
          "530e5961049e75a9262cffe0",
          "530e5961049e75a9262d0027",
          "530e5961049e75a9262d008d",
          "530e5963049e75a9262d0180",
          "530e5964049e75a9262d0300",
          "530e5964049e75a9262d0302",
          "530e5964049e75a9262d0304",
          "530e5965049e75a9262d039e",
          "530e5965049e75a9262d03b6",
          "530e5965049e75a9262d03e8",
          "530e5966049e75a9262d040c",
          "530e5966049e75a9262d04cc",
          "530e5967049e75a9262d05c0",
          "530e5968049e75a9262d062f"
        ],
        "subject": "homeroom/advisory",
        "teacher": "530e5955d50c310f36112c11",
        "teachers": [
          "530e5955d50c310f36112c11"
        ],
        "term": {
          "name": "Y1",
          "start_date": "2012-08-01",
          "end_date": "2013-06-01"
        },
        "id": "530e5979049e75a9262d0af2"
      },
      "uri": "/v1.1/sections/530e5979049e75a9262d0af2"
    },
    {
    "data": {
        "course_name": "Group Guidance",
        "course_number": "101",
        "created": "2014-02-26T21:15:37.927Z",
        "district": "4fd43cc56d11340000000005",
        "grade": "10",
        "last_modified": "2014-12-29T15:49:36.680Z",
        "name": "Group Guidance - 101 - B. Greene (Section 1)",
        "period": "0",
        "school": "530e595026403103360ff9fd",
        "sis_id": "581",
        "students": [
          "530e5960049e75a9262cff4f",
          "530e5960049e75a9262cff95",
          "530e5961049e75a9262cffe0",
          "530e5961049e75a9262d0027",
          "530e5961049e75a9262d008d",
          "530e5963049e75a9262d0180",
          "530e5964049e75a9262d0300",
          "530e5964049e75a9262d0302",
          "530e5964049e75a9262d0304",
          "530e5965049e75a9262d039e",
          "530e5965049e75a9262d03b6",
          "530e5965049e75a9262d03e8",
          "530e5966049e75a9262d040c",
          "530e5966049e75a9262d04cc",
          "530e5967049e75a9262d05c0",
          "530e5968049e75a9262d062f"
        ],
        "subject": "homeroom/advisory",
        "teacher": "530e5955d50c310f36112c11",
        "teachers": [
          "530e5955d50c310f36112c11"
        ],
        "term": {
          "name": "Y1",
          "start_date": "2012-08-01",
          "end_date": "2013-06-01"
        },
        "id": "530e5979049e75a9262d0af2"
      },
      "uri": "/v1.1/sections/530e5979049e75a9262d0af2"
    },
    ],
  "paging": {
    "current": 1,
    "total": 4,
    "count": 379
  },
  "links": [
    {
      "rel": "self",
      "uri": "/v1.1/sections"
    },
    {
      "rel": "next",
      "uri": "/v1.1/sections?starting_after=530e597a049e75a9262d0b55"
    }
  ]
}
"""

