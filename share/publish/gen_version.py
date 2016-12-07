import sys, os
import xml.etree.ElementTree as ET

def loadMapVersion(basepath, versionfile):
    mapVersion = {}
    maxVersion = 0
    with open(versionfile, 'r') as f:
        for line in f:
            packs = line.rstrip().split()
            if len(packs) == 2:
                name, version = packs
                name = os.path.normpath(os.path.relpath(name, basepath))
                mapVersion[name] = version
                maxVersion = max(int(version), int(maxVersion))
    return mapVersion, maxVersion

def main():
    if len(sys.argv) <> 7:
        print 'usage: %s basepath bundlepath version.txt path-to-bundleInfo.xml path-to-output-bundleInfo.xml resource-level' % sys.argv[0]
        exit(1)

    basepath, bundlepath, versionfile, bundleinfo, output, resourcelevel = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6]
    
    mapVersion, maxVersion = loadMapVersion(basepath, versionfile)

    toRemove = []
    bundleInfo = ET.parse(bundleinfo)
    for bundle in bundleInfo.getroot():
        name = os.path.normpath(os.path.relpath(bundle.attrib['path'], 'Assets'))

        
        if name in mapVersion:
            url = os.path.normpath(bundle.attrib['url'])
            if not os.path.exists(os.path.join(bundlepath, url)):
                print 'not exist:', os.path.join(bundlepath, url)
                toRemove.append(bundle)
                continue
            version = mapVersion[name]
            bundle.attrib['version'] = version
            bundle.attrib['server'] = os.path.join(resourcelevel, maxVersion, url).replace('\\', '/')
        else:
            print 'WARNING: %s does not exist' % name
            
    for bundle in toRemove:
        bundleInfo.getroot().remove(bundle)
        
    bundleInfo.write(output)

if __name__ == '__main__':
    main()
