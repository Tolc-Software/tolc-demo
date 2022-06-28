#import <Foundation/Foundation.h>
#import <MyCppLib.h>

int main() {
	@autoreleasepool {
		// Hello Tolc!
		NSLog(@"%@", [MyCppLibHello cppFunction:@"Tolc"]);
	}
}
