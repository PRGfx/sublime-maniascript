#!/usr/env/python
import sys
import os
import re
import json

def usage():
	print('Usage: python %s <big.h path>' % sys.argv[0])

def createCompletion(trigger, content, helper=None):
	helperText = ""
	if helper is not None:
		helperText = "\\t" + helper
	return {
		'trigger': trigger + helperText,
		'contents': content
	}

def parseBigH(bigFileContent):
	completions = []
	# classes
	classRe = re.compile('^\s*class\s(.*?)\s*\{', re.M)
	classes = re.findall(classRe, bigFileContent)
	for x in classes:
		completions.append(createCompletion(x, x))
	# structs
	structsRe = re.compile('struct\s+(\w+).*?\{((\s*enum\s+(\w+)\s*\{.*?\};)+.*?)\};', re.S)
	enumRe = re.compile('enum\s+(\w+)\s*\{(.*?)\};', re.S);
	# membersRe = re.compile('^\s*(const\s+)?(\w+)\s(\S+?);', re.M)
	membersRe = re.compile('(const\s)?\s*(\w+)\s(\S+?(\(.*?\))?);', re.M)
	structs = re.findall(structsRe, bigFileContent)
	for [structName, body, a, b] in structs:
		completions.append(createCompletion(structName, structName))
		enums = re.findall(enumRe, body);
		for [enumName, enumValues] in enums:
			for enumValue in list(filter(None, map(lambda x : x.strip(), enumValues.split(',')))):
				enumTitle = '::'.join([structName, enumName, enumValue])
				completions.append(createCompletion(enumTitle, enumTitle))
		members = re.findall(membersRe, body)
		for [_1, memberType, memberName, _2] in members:
			memberTitle = memberType.strip() + ' ' + structName
			if memberName.endswith(')'):
				parts = memberName[:-1].split('(')
				if parts[1].strip() == "":
					memberArgs = ''
				else:
					memberArgs = ', '.join(['${' + str(i + 1) + ':' + x + '}' for i, x in enumerate(parts[1].split(','))])
					# memberArgs = ', '.join(['${' + x + '}' for i, x in enumerate(parts[1].split(','))])
				completions.append(createCompletion(memberTitle + '.' + parts[0] + '('  + ', '.join(map(lambda x: x.strip(), parts[1].split(','))) + ')',\
					parts[0] + '('  + memberArgs + ')'))
			else:
				completions.append(createCompletion(memberTitle + '.' + memberName, memberName))
	return completions

def writeCompletions(data, outputFile, scope):
	data = {'scope': scope, 'completions': data}
	with open(outputFile, 'w') as outfile:
		json.dump(data, outfile, indent = 4, ensure_ascii = False)

def main(args):
	if len(args) < 1:
		usage()
		sys.exit(1)
	bigFile = args[0]
	if not os.path.exists(bigFile):
		print('big.h file not found!')
		sys.exit(1)
	with open(bigFile, 'r') as f:
		bigFileContent = f.read()
	completions = parseBigH(bigFileContent)
	writeCompletions(completions, 'ManiaScript.sublime-completions', 'source.ms')

if __name__ == "__main__":
	main(sys.argv[1:])