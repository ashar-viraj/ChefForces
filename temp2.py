import boto3
import json
import os
from boto3.dynamodb.conditions import Key, Attr
from boto3.dynamodb.types import TypeDeserializer, TypeSerializer
import traceback
import decimal
deserializer = boto3.dynamodb.types.TypeDeserializer()
dynamodb = boto3.resource('dynamodb')
PlayBookTable=os.environ['DYNAMODB_PLAYBOOK']
TopicsTable=os.environ['DYNAMODB_TOPICS']
StrategyTable=os.environ['DYNAMODB_STRATEGY']
CallforActionTable=os.environ['DYNAMODB_CALLFORACTION']
PlayBook = dynamodb.Table(PlayBookTable)
Topics = dynamodb.Table(TopicsTable)
Strategy = dynamodb.Table(StrategyTable)
CallforAction = dynamodb.Table(CallforActionTable)

class DecimalEncoder(json.JSONEncoder):
    def default(self, obj):
        if isinstance(obj, decimal.Decimal):
            return str(obj)
        return json.JSONEncoder.default(self, obj)
def deserializerData(item):
    item={k: deserializer.deserialize(v) for k,v in item.items()}
    return item

def TopicsThemesCallActionDependencyUpdate(event, context):
    try:
        Records=event.get('Records',None)
        if Records!=None:
            for rd in Records:
                dynamodbdata=rd.get('dynamodb',None)
                SourceARN=rd.get('eventSourceARN',None)
                if dynamodbdata!=None and SourceARN != None:
                    SourceARN=SourceARN.lower()
                    NewImage=dynamodbdata.get('NewImage',None)
                    OldImage=dynamodbdata.get('OldImage',None)
                    Keys=dynamodbdata.get('Keys',None)
                    if Keys!=None:
                        Keys=deserializerData(Keys)
                        print('Keys:',Keys)
                        customerid=Keys.get('customerId','')
                    if NewImage!=None:
                        NewImage=deserializerData(NewImage)
                    if OldImage!=None:
                        OldImage=deserializerData(OldImage)
                    NewTopicsDependencyData=[]
                    NewThemesDependencyData=[]
                    NewCallforActionDependencyData=[]
                    OldTopicsDependencyData=[]
                    OldThemesDependencyData=[]
                    OldCallforActionDependencyData=[]
                    if u'playbook' in SourceARN:
                        if NewImage!=None:
                            PlayBookNewData = NewImage
                            Dependency={'type':'playbook','name':PlayBookNewData['playbookName'],'id':PlayBookNewData['playBookId']}
                            if u'cfacondition' in PlayBookNewData:
                                for cf in PlayBookNewData['cfacondition']:
                                    if u'Dimension' in cf and  u'Measure' in cf and  cf['Dimension'].lower()=='topic':
                                        if not cf['Measure']  in NewTopicsDependencyData:
                                            print("62 - NewTopicsDependencyData")
                                            NewTopicsDependencyData.append(cf['Measure'])
                                    elif u'Dimension' in cf  and u'Theme' in cf and  cf['Dimension'].lower()=='score' and cf['Theme']!=None:
                                        if not cf['Theme'] in NewThemesDependencyData:
                                            NewThemesDependencyData.append(cf['Theme'])
                            if u'callActionList' in PlayBookNewData:
                                for cal in PlayBookNewData['callActionList']:
                                    callActionId=cal.get('callActionId')
                                    if callActionId!=None and callActionId!='':
                                        if not callActionId in NewCallforActionDependencyData:
                                            NewCallforActionDependencyData.append(callActionId)
                        if OldImage!=None:
                            PlayBookOldData = OldImage
                            Dependency={'type':'playbook','name':PlayBookOldData['playbookName'],'id':PlayBookOldData['playBookId']}
                            if u'cfacondition' in PlayBookOldData:
                                for cf in PlayBookOldData['cfacondition']:
                                    if u'Dimension' in cf and  u'Measure' in cf and  cf['Dimension'].lower()=='topic':
                                        if not cf['Measure']  in OldTopicsDependencyData and not cf['Measure'] in NewTopicsDependencyData:
                                            print("81 -> OldTopicsDependencyData")
                                            OldTopicsDependencyData.append(cf['Measure'])
                                    elif u'Dimension' in cf  and u'Theme' in cf and  cf['Dimension'].lower()=='score' and cf['Theme']!=None:
                                        if not cf['Theme'] in OldThemesDependencyData and not cf['Theme'] in NewThemesDependencyData:
                                            OldThemesDependencyData.append(cf['Theme'])
                            if u'callActionList' in PlayBookOldData:
                                for cal in PlayBookOldData['callActionList']:
                                    callActionId=cal.get('callActionId')
                                    if callActionId!=None and callActionId!='':
                                        if not callActionId in OldCallforActionDependencyData and not callActionId in NewCallforActionDependencyData:
                                            OldCallforActionDependencyData.append(callActionId)
                                            
                        print("NewTopicsDependencyData")
                        print(len(NewTopicsDependencyData))
                        for key in NewTopicsDependencyData:
                            print(key)
                            
                        print("OldTopicsDependencyData")
                        print(len(OldTopicsDependencyData))
                        for key in OldTopicsDependencyData:
                            print(key)
                    
                        
                        if len(NewTopicsDependencyData)>0 or len(OldTopicsDependencyData)>0:
                            print("92")
                            UpdateTopicDependency(customerid,Dependency,NewTopicsDependencyData,OldTopicsDependencyData)
                        if len(NewThemesDependencyData)>0 or len(OldThemesDependencyData)>0:
                            UpdateThemeDependency(customerid,Dependency,NewThemesDependencyData,OldThemesDependencyData)
                        if len(NewCallforActionDependencyData)>0 or len(OldCallforActionDependencyData)>0:
                            UpdateCallforActionDependency(customerid,Dependency,NewCallforActionDependencyData,OldCallforActionDependencyData)

                    elif u'strategy' in SourceARN:
                        if NewImage!=None:
                            StrategyNewData= NewImage
                            Dependency={'type':'themes','name':StrategyNewData['strategyName'],'id':StrategyNewData['strategyId']}
                            if u'topicScore' in StrategyNewData:
                                for ts in StrategyNewData['topicScore']:
                                    if u'topicId' in ts:
                                        if not ts['topicId']  in NewTopicsDependencyData:
                                            NewTopicsDependencyData.append(ts['topicId'])
                        if OldImage!=None:
                            StrategyOldData= OldImage
                            Dependency={'type':'themes','name':StrategyOldData['strategyName'],'id':StrategyOldData['strategyId']}
                            if u'topicScore' in StrategyOldData:
                                for ts in StrategyOldData['topicScore']:
                                    if u'topicId' in ts:
                                        if not ts['topicId']  in OldTopicsDependencyData and not ts['topicId'] in NewTopicsDependencyData:
                                            OldTopicsDependencyData.append(ts['topicId'])
                        if len(NewTopicsDependencyData)>0 or len(OldTopicsDependencyData)>0:
                                    UpdateTopicDependency(customerid,Dependency,NewTopicsDependencyData,OldTopicsDependencyData)
            
    except:
        print('Errorinfo:',traceback.format_exc())
def UpdateTopicDependency(customerid,Dependency,TopicsDependencyData,OldTopicsDependencyData):
    for tp in TopicsDependencyData:
        Topicsdata = Topics.get_item(Key={'customerId':customerid,'topicId':tp})
        Topicsdata=Topicsdata.get('Item',None)
        if Topicsdata!=None:
            dependencylist=[]
            if u'dependency' in Topicsdata:
                if not  Dependency in Topicsdata['dependency']:
                    print("127")
                    Topicsdata['dependency'].append(Dependency)
                    dependencylist=Topicsdata['dependency']
            else:
                dependencylist.append(Dependency)
            if len(dependencylist)>0:
                print("135")
                UpdateTopicTable(customerid,tp,dependencylist)
    for otp in OldTopicsDependencyData:
        Topicsdata = Topics.get_item(Key={'customerId':customerid,'topicId':otp})
        Topicsdata=Topicsdata.get('Item',None)
        if Topicsdata!=None:
            if u'dependency' in Topicsdata:
                dependencylist=[]
                for td in  Topicsdata['dependency']:
                    print("Td")
                    for key,value in td.items():
                        print(key," ", value, " td")
                    print("Dependency")
                    for key,value in Dependency.items():
                        print(key," ",value, " Dep")
                    if sorted(td.items()) != sorted(Dependency.items()):
                        print("145")
                        dependencylist.append(td)
                UpdateTopicTable(customerid,otp,dependencylist)

def UpdateThemeDependency(customerid,Dependency,ThemesDependencyData,OldThemesDependencyData):
    for tp in ThemesDependencyData:
        Themesdata = Strategy.get_item(Key={'customerId':customerid,'strategyId':tp})
        Themesdata=Themesdata.get('Item',None)
        if Themesdata!=None:
            dependencylist=[]
            if u'dependency' in Themesdata:
                if not  Dependency in Themesdata['dependency']:
                    Themesdata['dependency'].append(Dependency)
                    dependencylist=Themesdata['dependency']
            else:
                dependencylist.append(Dependency)
            if len(dependencylist)>0:
                UpdateThemesTable(customerid,tp,dependencylist)
    for otp in OldThemesDependencyData:
        Themesdata = Strategy.get_item(Key={'customerId':customerid,'strategyId':otp})
        Themesdata=Themesdata.get('Item',None)
        if Themesdata!=None:
            if u'dependency' in Themesdata:
                dependencylist=[]
                for td in  Themesdata['dependency']:
                    if sorted(td.items()) != sorted(Dependency.items()):
                        dependencylist.append(td)
                UpdateThemesTable(customerid,otp,dependencylist)


def UpdateCallforActionDependency(customerid,Dependency,NewCallforActionDependencyData,OldCallforActionDependencyData):
    for cfa in NewCallforActionDependencyData:
        CallforActiondata = CallforAction.get_item(Key={'customerId':customerid,'callActionId':cfa})
        CallforActiondata=CallforActiondata.get('Item',None)
        if CallforActiondata!=None:
            dependencylist=[]
            if u'dependency' in CallforActiondata and  not  Dependency in CallforActiondata['dependency']:
                CallforActiondata['dependency'].append(Dependency)
                dependencylist=CallforActiondata['dependency']
            else:
                dependencylist.append(Dependency)
            if len(dependencylist)>0:
                UpdateCallForActionTable(customerid,cfa,dependencylist)
    for ocfa in OldCallforActionDependencyData:
        CallforActiondata = CallforAction.get_item(Key={'customerId':customerid,'callActionId':ocfa})
        CallforActiondata=CallforActiondata.get('Item',None)
        if CallforActiondata!=None:
            if u'dependency' in CallforActiondata:
                dependencylist=[]
                for td in  CallforActiondata['dependency']:
                    if sorted(td.items()) != sorted(Dependency.items()):
                        dependencylist.append(td)
                UpdateCallForActionTable(customerid,ocfa,dependencylist)


def UpdateTopicTable(customerid,id,dependencylist):
    response = Topics.update_item(
    Key={'customerId': customerid,'topicId':id},
    UpdateExpression="set dependency=:dependency",
    ExpressionAttributeValues={
        ':dependency': dependencylist,    
    })

def UpdateThemesTable(customerid,id,dependencylist):
    response = Strategy.update_item(
    Key={'customerId': customerid,'strategyId':id},
    UpdateExpression="set dependency=:dependency",
    ExpressionAttributeValues={
        ':dependency': dependencylist,    
    })

def UpdateCallForActionTable(customerid,id,dependencylist):
    response = CallforAction.update_item(
    Key={'customerId': customerid,'callActionId':id},
    UpdateExpression="set dependency=:dependency",
    ExpressionAttributeValues={
        ':de